#include "DiceThrower.h"

#include <string>

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "PDA_Dice.h"
#include "DiceActor.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/AssetManager.h"

// Sets default values
ADiceThrower::ADiceThrower()
{
	// Create and set the debug arrow component as a child of the root
	DebugArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("DebugArrow"));
	RootComponent = DebugArrow;

	// Create and set the box component for visualizing the spawn area
	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	SpawnBox->SetupAttachment(RootComponent);

	// Set default box extent and make it visible in the editor
	SpawnBox->SetBoxExtent(SpawnBoxExtent);
	SpawnBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpawnBox->SetVisibility(true);
	SpawnBox->SetHiddenInGame(true);

	// Default values
	LaunchForce = 150.0f;
	SpawnBoxExtent = FVector(5.0f, 10.0f, 5.0f);
}

// Called when the game starts or when spawned
void ADiceThrower::BeginPlay()
{
	Super::BeginPlay();
}

// Called when the construction script runs
void ADiceThrower::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SpawnBox->SetBoxExtent(SpawnBoxExtent);
}

// Spawn all dice specified in the DiceArray using Asynchronous Asset Loading
void ADiceThrower::SpawnDice()
{
	for (UPDA_Dice* DiceData : DiceArray)
	{
		if (DiceData)
		{
			// Get the AssetManager
			UAssetManager& AssetManager = UAssetManager::Get();

			// Get the primary asset ID for the DiceData
			FPrimaryAssetId AssetId = DiceData->GetPrimaryAssetId();

			// Specify the bundles to load (e.g., "Game")
			TArray<FName> BundlesToLoad;
			BundlesToLoad.Add(FName("Game"));

			// Set up the delegate to call once the assets are loaded
			FStreamableDelegate OnAssetsLoadedDelegate = FStreamableDelegate::CreateUObject(this, &ADiceThrower::OnAssetsLoaded, DiceData);

			// Asynchronously load the assets in the "Game" bundle
			AssetManager.LoadPrimaryAsset(AssetId, BundlesToLoad, OnAssetsLoadedDelegate);
		}
	}
}

// Callback function after asynchronous asset loading
void ADiceThrower::OnAssetsLoaded(UPDA_Dice* DiceData)
{
	if (DiceData)
	{
		// Now that the assets are loaded, retrieve them
		TSubclassOf<ADiceActor> DiceClass = DiceData->DiceClass.Get();
		UStaticMesh* DiceMesh = DiceData->DiceMesh.Get();
		UMaterialInterface* DiceMaterial = DiceData->DiceMaterial.Get();

		if (DiceClass && DiceMesh && DiceMaterial)
		{
			// Random spawn location within the box
			FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
			FRotator SpawnRotation = UKismetMathLibrary::RandomRotator(true);

			// Spawn the dice actor in a deferred state
			ADiceActor* SpawnedDiceActor = GetWorld()->SpawnActorDeferred<ADiceActor>(DiceClass, FTransform(SpawnRotation, SpawnLocation));

			if (SpawnedDiceActor)
			{
				// Assign the loaded data to the dice actor
				SpawnedDiceActor->DiceData = DiceData;
				SpawnedDiceActor->DiceMeshComponent->SetStaticMesh(DiceMesh);
				SpawnedDiceActor->DiceMeshComponent->SetMaterial(0, DiceMaterial);

				// Complete the actor spawning process
				SpawnedDiceActor->FinishSpawning(FTransform(SpawnRotation, SpawnLocation));

				// Wake up the physics body to ensure it's ready for an impulse
				SpawnedDiceActor->DiceMeshComponent->WakeRigidBody(NAME_None);

				// Bind to the OnDiceResult event
				SpawnedDiceActor->OnDieResult.AddDynamic(this, &ADiceThrower::OnDiceResult);
				SpawnedDiceActor->OnDieClicked.AddDynamic(this, &ADiceThrower::RerollDice);
				SpawnedDice.Add(SpawnedDiceActor);

				// Broadcast that a die has been spawned
				OnDieSpawned.Broadcast(SpawnedDiceActor);

				// Now that everything is loaded and initialized, launch the die
				LaunchDie(SpawnedDiceActor);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load dice assets asynchronously."));
		}
	}
}

// Launch a single die
void ADiceThrower::LaunchDie(ADiceActor* Die)
{
	if (Die)
	{
		// Delay the impulse application by 0.1 seconds to ensure the physics body is fully initialized
		FTimerHandle TimerHandle;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, Die]()
		{
			if (Die && Die->DiceMeshComponent)
			{
				// Launch the die in the direction of the arrow with specified force
				FVector LaunchDirection = DebugArrow->GetForwardVector();
				Die->DiceMeshComponent->AddImpulse(LaunchDirection * LaunchForce, NAME_None, true);

				// Broadcast that a die has been thrown
				OnDieThrown.Broadcast(Die);
			}
		}, 0.01f, false);  // Delay of 0.01 seconds
	}
}

void ADiceThrower::RerollAll()
{
	DiceResultsMap.Empty();
	for (ADiceActor* Dice : SpawnedDice)
	{
		if (Dice && Dice->DiceMeshComponent)
		{
			// Randomize the position and rotation inside the spawn box
			FVector NewLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
			FRotator NewRotation = UKismetMathLibrary::RandomRotator(true);

			// Set the new location and rotation for the dice
			Dice->SetActorLocationAndRotation(NewLocation, NewRotation, false, nullptr, ETeleportType::TeleportPhysics);

			RerollDice(Dice);
		}
	}
	OnResultChanged.Broadcast(FText::FromString(FString::FromInt(0)));
}

void ADiceThrower::RerollDice(ADiceActor* Die)
{
	if (Die->DiceMeshComponent)
	{
		Die->HandleEndCursorOver(nullptr);
		
		// Randomize the position and rotation inside the spawn box
		FVector NewLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
		FRotator NewRotation = UKismetMathLibrary::RandomRotator(true);

		// Set the new location and rotation for the dice
		Die->SetActorLocationAndRotation(NewLocation, NewRotation, false, nullptr, ETeleportType::TeleportPhysics);

		// Wake up the physics body to ensure it's ready for an impulse
		Die->DiceMeshComponent->WakeRigidBody(NAME_None);

		// Apply the launch force (re-roll the dice)
		FVector LaunchDirection = DebugArrow->GetForwardVector();
		Die->DiceMeshComponent->AddImpulse(LaunchDirection * LaunchForce, NAME_None, true);

		// Random torque
		FVector Torque = FVector::UpVector * FMath::RandRange(1000.0f, 2000.0f); 
		Die->DiceMeshComponent->AddTorqueInRadians(Torque, NAME_None, true);

		// Optionally update the die state if you are tracking it
		Die->SetDieState(EDieState::Rolling);
	}
}

void ADiceThrower::OnDiceResult(ADiceActor* Die, FText Result)
{
	// Convert the result to a string
	FString ResultString = Result.ToString();

	// Update the result for this particular dice in the map (overwriting the old value)
	DiceResultsMap.FindOrAdd(Die, ResultString);

	// Recalculate the total and handle non-numeric results from the entire map
	int32 TotalResult = 0;
	TArray<FString> NonNumericResults;

	// Iterate through the map to calculate the total result
	for (const TPair<ADiceActor*, FString>& DiceResult : DiceResultsMap)
	{
		const FString& DiceValueString = DiceResult.Value;

		// Check if the result is numeric
		if (DiceValueString.IsNumeric())
		{
			// Convert to an integer and add to the total
			int32 DiceValue = FCString::Atoi(*DiceValueString);
			TotalResult += DiceValue;
		}
		else
		{
			// Store non-numeric result in an array
			NonNumericResults.Add(DiceValueString);
		}
	}

	// Format the result as "total, non-numeric values"
	FString FinalResult;

	// If we have a numeric total, include it
	if (TotalResult > 0)
	{
		FinalResult = FString::FromInt(TotalResult);
	}

	// Add non-numeric results if they exist
	if (NonNumericResults.Num() > 0)
	{
		// Add a separator if we have both numeric and non-numeric values
		if (TotalResult > 0)
		{
			FinalResult += ", ";
		}
		FinalResult += FString::Join(NonNumericResults, TEXT(", "));
	}

	// Convert the final result to FText for broadcasting
	FText FinalResultText = FText::FromString(FinalResult);

	// Broadcast the updated result
	OnResultChanged.Broadcast(FinalResultText);

	// Log the updated result
	UE_LOG(LogTemp, Log, TEXT("Updated Dice Result: %s"), *FinalResult);
}

void ADiceThrower::OnDieClicked(ADiceActor* Die)
{
	RerollDice(Die);
}

// Reset and delete all spawned dice
void ADiceThrower::ClearDice()
{
	// Destroy all spawned dice actors
	for (ADiceActor* DiceActor : SpawnedDice)
	{
		if (DiceActor && !DiceActor->IsPendingKillPending())
		{
			DiceActor->Destroy();
		}
	}

	// Clear the array of spawned dice references
	SpawnedDice.Empty();
	DiceResultsMap.Empty();
	
	// Broadcast that all dice have been cleared
	OnDiceCleared.Broadcast();
}

// Add a dice data asset to the array
void ADiceThrower::AddDice(UPDA_Dice* Dice)
{
	if (Dice)
	{
		DiceArray.Add(Dice);
	}
}

// Remove a dice data asset from the array
void ADiceThrower::RemoveDice(UPDA_Dice* Dice)
{
	if (Dice)
	{
		DiceArray.RemoveSingle(Dice);
	}
}
