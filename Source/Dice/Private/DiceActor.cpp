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
	Streamable.RequestAsyncLoad(DiceData.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ADiceActor::OnDiceDataLoaded));
}

void ADiceActor::OnDiceDataLoaded()
{
	// Now that DiceData is loaded, get the pointer
	if (UPDA_Dice* LoadedData = DiceData.Get())
	{
		if (LoadedData)
		{
			// Get the streamable manager
			FStreamableManager& Streamable = UAssetManager::GetStreamableManager();

			// Asynchronously load the DiceMesh
			Streamable.RequestAsyncLoad(LoadedData->DiceMesh.ToSoftObjectPath(), FStreamableDelegate::CreateUObject(this, &ADiceActor::OnDiceMeshLoaded));
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
			// Set the static mesh
			DiceMeshComponent->SetStaticMesh(LoadedMesh);
		}
	}
}

void ADiceActor::BeginPlay()
{
	Super::BeginPlay();
}
		