/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */


#include "Actors/DiceActor.h"
#include "DataAssets/PDA_Dice.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Actors/DiceDecal.h"
#include "Engine/AssetManager.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADiceActor::ADiceActor()
{
	// Create and set the DiceMeshComponent as the root component
	DiceMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DiceMeshComponent"));
	RootComponent = DiceMeshComponent;

	// Set default collision and physics properties
	DiceMeshComponent->SetSimulatePhysics(true);
	DiceMeshComponent->SetCollisionProfileName(TEXT("Dice"));
	DiceMeshComponent->SetReceivesDecals(false);
    DiceMeshComponent->SetNotifyRigidBodyCollision(true);
	
	// Bind to the sleep event of the physics simulation
	DiceMeshComponent->BodyInstance.bGenerateWakeEvents = true;
	DiceMeshComponent->OnComponentSleep.AddDynamic(this, &ADiceActor::HandlePhysicsSleep);

	//Tweak the default physics settings
	DiceMeshComponent->BodyInstance.SleepFamily = ESleepFamily::Custom;
	DiceMeshComponent->BodyInstance.CustomSleepThresholdMultiplier = 0.80f;
	DiceMeshComponent->SetLinearDamping(1.0f);
	DiceMeshComponent->SetAngularDamping(1.0f);

	// bind the onhover and broadcast our custom delegate
	DiceMeshComponent->OnBeginCursorOver.AddDynamic(this, &ADiceActor::HandleBeginCursorOver);
	DiceMeshComponent->OnEndCursorOver.AddDynamic(this, &ADiceActor::HandleEndCursorOver);
	DiceMeshComponent->OnClicked.AddDynamic(this, &ADiceActor::HandleOnClicked);
	DiceMeshComponent->OnComponentHit.AddDynamic(this, &ADiceActor::HandleOnHit);

	//Replication
	//SetReplicates(true);
	//SetReplicatingMovement(true);
	//DiceMeshComponent->SetIsReplicated(true);

	// Die state
	DieState = EDieState::Idle;
}

EDieState ADiceActor::GetDieState() const
{
	return DieState;
}

void ADiceActor::SetDieState(const EDieState NewDieState)
{
	if (NewDieState != DieState)
	{
		DieState = NewDieState;
		OnDieStateChanged.Broadcast(this, DieState);
	}
}

// Initialize the dice actor based on the data asset
void ADiceActor::InitializeDice()
{
	// Check if the DiceData is valid
	if (!DiceId.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("DiceId is not set!"));
		return;
	}
	
	UAssetManager& AssetManager = UAssetManager::Get();
	if (const UPDA_Dice* DiceData = Cast<UPDA_Dice>(AssetManager.GetPrimaryAssetObject(DiceId)))
	{
		DiceMeshComponent->SetStaticMesh(DiceData->DiceMesh.Get());
		DiceMeshComponent->SetMaterial(0, DiceData->DiceMaterial.Get());	
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("DiceActor: Object from DiceId was not valid, using fallback method"))
		DiceMeshComponent->SetStaticMesh(DiceData->DiceMesh.LoadSynchronous());
		DiceMeshComponent->SetMaterial(0, DiceData->DiceMaterial.LoadSynchronous());	
	}
}


void ADiceActor::HandlePhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName)
{
	// Physics simulation has gone to sleep; calculate and broadcast the dice result
	FText DiceResult = CalculateDiceResult();
	UE_LOG(LogTemp, Log, TEXT("Physics sleep detected. Dice result is: %s"), *DiceResult.ToString());
	
	if(CheckValidity())
	{
		SetDieState(EDieState::Stopped);
		OnDieResult.Broadcast(this, DiceResult);
	}
	else SetDieState(EDieState::Invalid);
}

FText ADiceActor::CalculateDiceResult() const
{
	// Check if the mesh and data are valid
	if (!DiceMeshComponent || !DiceId.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("DiceMeshComponent or DiceData is not valid."));
		return FText::FromString("Invalid");
	}

	UAssetManager& AssetManager = UAssetManager::Get();
	const UPDA_Dice* DiceData = Cast<UPDA_Dice>(AssetManager.GetPrimaryAssetObject(DiceId));

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
	if (HighestSocketName != NAME_None && DiceData->FaceLabels.Contains(HighestSocketName.ToString()))
	{
		// Get the label from the map
		FText FaceLabel = DiceData->FaceLabels[HighestSocketName.ToString()];
		return FaceLabel;
	}

	// If no valid label found
	UE_LOG(LogTemp, Warning, TEXT("No valid label found for the highest socket."));
	return FText::FromString("Unknown");
}

bool ADiceActor::CheckValidity() const
{
	FVector ActorUpVector = GetActorUpVector().GetSafeNormal();
	UAssetManager& AssetManager = UAssetManager::Get();
	const UPDA_Dice* DiceData = Cast<UPDA_Dice>(AssetManager.GetPrimaryAssetObject(DiceId));

    for (const FVector& FaceNormal : DiceData->FaceNormals)
	{
    	// Normalize the current face normal
    	const FVector NormalizedFaceNormal = FaceNormal.GetSafeNormal();

    	// Error tolerance value
    	float ErrorTolerance = 0.05f;

    	// Check if each component of the vectors is nearly equal
    	const bool bXEqual = FMath::IsNearlyEqual(NormalizedFaceNormal.X, ActorUpVector.X, ErrorTolerance);
    	const bool bYEqual = FMath::IsNearlyEqual(NormalizedFaceNormal.Y, ActorUpVector.Y, ErrorTolerance);
    	const bool bZEqual = FMath::IsNearlyEqual(NormalizedFaceNormal.Z, ActorUpVector.Z, ErrorTolerance);

    	// If all components are nearly equal, set a valid flag, else set invalid
    	if (bXEqual || bYEqual || bZEqual) return true;
	}
	return false;
}

void ADiceActor::BeginPlay()
{
	Super::BeginPlay();
	
	InitializeDice();
}

void ADiceActor::HandleBeginCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (!DiceDecal.IsNull()  && DieState == EDieState::Stopped)
	{
		// Load the class from the soft class pointer
		UClass* DecalClass = DiceDecal.LoadSynchronous();

		if (DecalClass)
		{
			// Spawn the decal actor at location (0, 0, 0) relative to the dice actor
			FVector SpawnLocation = FVector(0.f, 0.f, 0.f); // Relative location
			FRotator SpawnRotation = FRotator::ZeroRotator; // No rotation
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this; // Set the owner to the dice actor
			SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			// Spawn the decal actor in the world using the loaded class
			ADiceDecal* DecalActor = GetWorld()->SpawnActor<ADiceDecal>(DecalClass, SpawnLocation, SpawnRotation, SpawnParams);

			if (DecalActor)
			{
				// Store the weak pointer reference
				SpawnedDecal = DecalActor;

				// Attach the decal to the dice actor with the equivalent of Blueprint setup
				FAttachmentTransformRules AttachRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, EAttachmentRule::KeepRelative, true);
				DecalActor->AttachToActor(this, AttachRules);
			}
		}
	}
	OnDieHover.Broadcast(this);
}



void ADiceActor::HandleEndCursorOver(UPrimitiveComponent* TouchedComponent)
{
	if (SpawnedDecal.IsValid())
	{
		// Destroy the decal actor
		SpawnedDecal->Destroy();
		SpawnedDecal = nullptr;  // Reset the pointer
	}
	
	OnDieHoverEnd.Broadcast(this);
}

void ADiceActor::HandleOnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed)
{
	OnDieClicked.Broadcast(this);
}

void ADiceActor::HandleOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	const float ImpactThreshold = .50f;

	if (NormalImpulse.Size() > ImpactThreshold)
	{
		if (DiceHitSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, DiceHitSound, GetActorLocation());
		}
	}
}