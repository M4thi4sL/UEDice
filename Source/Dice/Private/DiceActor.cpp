#include "DiceActor.h"
#include "PDA_Dice.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/StreamableManager.h"
#include "Engine/AssetManager.h"

// Sets default values
ADiceActor::ADiceActor()
{
	// Create and set the DiceMeshComponent as the root component
	DiceMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DiceMeshComponent"));
	RootComponent = DiceMeshComponent;

	// Set default collision and physics properties
	DiceMeshComponent->SetSimulatePhysics(true);
	DiceMeshComponent->SetCollisionProfileName(TEXT("Dice"));

	// Bind to the sleep event of the physics simulation
	DiceMeshComponent->OnComponentSleep.AddDynamic(this, &ADiceActor::HandlePhysicsSleep);

	//Tweak the default physics settings
	DiceMeshComponent->BodyInstance.SleepFamily = ESleepFamily::Custom;
	DiceMeshComponent->BodyInstance.CustomSleepThresholdMultiplier = 15.0f;
	DiceMeshComponent->SetLinearDamping(1.0f);
	DiceMeshComponent->SetAngularDamping(1.0f);
}

// Called when an instance of this class is constructed (editor or runtime)
void ADiceActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Initialize the dice with the data asset
	InitializeDice();
}

// Initialize the dice actor based on the data asset
void ADiceActor::InitializeDice()
{
	// Check if the DiceData is valid
	if (DiceData.IsNull())
	{
		UE_LOG(LogTemp, Warning, TEXT("DiceData is not set!"));
		return;
	}

	// Get the streamable manager
	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();

	// Asynchronously load the DiceData asset
	UE_LOG(LogTemp, Log, TEXT("Requesting async load for DiceData: %s"), *DiceData.ToSoftObjectPath().ToString());
	Streamable.RequestAsyncLoad(DiceData.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ADiceActor::OnDiceDataLoaded));
}

void ADiceActor::OnDiceDataLoaded()
{
	// Now that DiceData is loaded, get the pointer
	if (UPDA_Dice* LoadedData = DiceData.Get())
	{
		UE_LOG(LogTemp, Log, TEXT("Successfully loaded DiceData: %s"), *DiceData.ToSoftObjectPath().ToString());

		if (LoadedData)
		{
			// Get the streamable manager
			FStreamableManager& Streamable = UAssetManager::GetStreamableManager();

			// Asynchronously load the DiceMesh
			UE_LOG(LogTemp, Log, TEXT("Requesting async load for DiceMesh: %s"), *LoadedData->DiceMesh.ToSoftObjectPath().ToString());
			Streamable.RequestAsyncLoad(LoadedData->DiceMesh.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ADiceActor::OnDiceMeshLoaded));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load DiceData! The asset might not exist or be corrupted."));
		}
	}
}

void ADiceActor::OnDiceMeshLoaded()
{
	// Now that DiceMesh is loaded, set the mesh on the component
	if (UPDA_Dice* LoadedData = DiceData.Get())
	{
		if (UStaticMesh* LoadedMesh = LoadedData->DiceMesh.Get())
		{
			UE_LOG(LogTemp, Log, TEXT("Successfully loaded DiceMesh: %s"), *LoadedData->DiceMesh.ToSoftObjectPath().ToString());

			// Set the static mesh
			DiceMeshComponent->SetStaticMesh(LoadedMesh);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load DiceMesh! The asset might not exist or be corrupted."));
		}
	}
}

void ADiceActor::HandlePhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName)
{
	// Physics simulation has gone to sleep; calculate and broadcast the dice result
	FString DiceResult = CalculateDiceResult();
	UE_LOG(LogTemp, Log, TEXT("Physics sleep detected. Dice result is: %s"), *DiceResult);

	// Broadcast the result to any listeners
	OnDiceResult.Broadcast(DiceResult);
}

FString ADiceActor::CalculateDiceResult() const
{
	// Check if the mesh and data are valid
	if (!DiceMeshComponent || DiceData.IsNull())
	{
		UE_LOG(LogTemp, Warning, TEXT("DiceMeshComponent or DiceData is not valid."));
		return FString("Invalid");
	}

	UPDA_Dice* LoadedData = DiceData.Get();
	if (!LoadedData)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get DiceData."));
		return FString("Invalid");
	}

	// Store the socket name with the highest position
	FName HighestSocketName;
	float MaxZ = -FLT_MAX; // Initialize to a very low value

	// Iterate through all sockets on the mesh
	for (const FName& SocketName : DiceMeshComponent->GetAllSocketNames())
	{
		// Get the socket's world position
		FTransform SocketTransform = DiceMeshComponent->GetSocketTransform(SocketName);
		FVector SocketPosition = SocketTransform.GetLocation();

		// Check if this socket is higher than the current max
		if (SocketPosition.Z > MaxZ)
		{
			MaxZ = SocketPosition.Z;
			HighestSocketName = SocketName;
		}
	}

	// If we have found a valid socket
	if (HighestSocketName != NAME_None && LoadedData->FaceLabels.Contains(HighestSocketName.ToString()))
	{
		// Get the label from the map
		FString FaceLabel = LoadedData->FaceLabels[HighestSocketName.ToString()];
		return FaceLabel;
	}

	// If no valid label found
	UE_LOG(LogTemp, Warning, TEXT("No valid label found for the highest socket."));
	return FString("Unknown");
}
void ADiceActor::BeginPlay()
{
	Super::BeginPlay();
}
