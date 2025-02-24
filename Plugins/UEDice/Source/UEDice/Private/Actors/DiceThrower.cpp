/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */


#include "Actors/DiceThrower.h"

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "DataAssets/PDA_Dice.h"
#include "Actors/DiceActor.h"
#include "Controller/DicePlayerState.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/AssetManager.h"
#include "Net/UnrealNetwork.h"

ADiceThrower::ADiceThrower()
{
	DebugArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("DebugArrow"));
	RootComponent = DebugArrow;

	SpawnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnBox"));
	SpawnBox->SetupAttachment(RootComponent);

	SpawnBox->SetBoxExtent(SpawnBoxExtent);
	SpawnBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SpawnBox->SetVisibility(true);
	SpawnBox->SetHiddenInGame(true);

	LaunchForce = 150.0f;
	SpawnBoxExtent = FVector(5.0f, 10.0f, 5.0f);
}

void ADiceThrower::BeginPlay()
{
	Super::BeginPlay();
}

void ADiceThrower::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SpawnBox->SetBoxExtent(SpawnBoxExtent);
}

void ADiceThrower::SpawnDice()
{
	if (HasAuthority())
	{
		for (FPrimaryAssetId DiceData : DiceArray)
		{
			if (DiceData.IsValid())
			{
				UAssetManager& AssetManager = UAssetManager::Get();

				TArray<FName> BundlesToLoad;
				BundlesToLoad.Add(FName("Game"));

				FStreamableDelegate OnAssetsLoadedDelegate = FStreamableDelegate::CreateLambda([this, DiceData]()
			   {
				   if (DiceData.IsValid()) OnAssetsLoaded(DiceData);
			   });
				AssetManager.LoadPrimaryAsset(DiceData, BundlesToLoad, OnAssetsLoadedDelegate);
			}
		}
	}
	else
	{
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC)
		{
			ADicePlayerState* PS = PC->GetPlayerState<ADicePlayerState>();
			if (PS)
			{
				PS->Server_RequestSpawnDice();
			}
		}
	}
}

void ADiceThrower::Multicast_SpawnDice_Implementation(ADiceActor* SpawnedDie)
{
	if (!HasAuthority())
	{
		SpawnedDice.Add(SpawnedDie);
	}
}

void ADiceThrower::Server_SpawnDice_Implementation()
{
	for (FPrimaryAssetId DiceData : DiceArray)
	{
		if (DiceData.IsValid())
		{
			UAssetManager& AssetManager = UAssetManager::Get();
			UPDA_Dice* DiceAsset = Cast<UPDA_Dice>(AssetManager.GetPrimaryAssetObject(DiceData));

			if (DiceAsset)
			{
				FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
				FRotator SpawnRotation = UKismetMathLibrary::RandomRotator(true);

				ADiceActor* SpawnedDiceActor = GetWorld()->SpawnActor<ADiceActor>(DiceAsset->DiceClass.Get(), SpawnLocation, SpawnRotation);

				if (SpawnedDiceActor)
				{
					SpawnedDiceActor->DiceId = DiceData;
					SpawnedDiceActor->SetDieState(EDieState::Idle);

					SpawnedDice.Add(SpawnedDiceActor);
					Multicast_SpawnDice(SpawnedDiceActor); // Send update to all clients
				}
			}
		}
	}
}

bool ADiceThrower::Server_SpawnDice_Validate()
{
	return true;
}

void ADiceThrower::Server_LaunchDie_Implementation(ADiceActor* Die)
{
	if (Die && Die->DiceMeshComponent)
	{
		FVector LaunchDirection = DebugArrow->GetForwardVector();
		Die->DiceMeshComponent->AddImpulse(LaunchDirection * LaunchForce, NAME_None, true);
		Die->SetDieState(EDieState::Rolling);
	}
}

bool ADiceThrower::Server_LaunchDie_Validate(ADiceActor* Die)
{
	return true;
}

void ADiceThrower::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ADiceThrower, SpawnedDice);

	DOREPLIFETIME(ADiceThrower, DiceArray);

}

void ADiceThrower::OnAssetsLoaded(const FPrimaryAssetId& LoadedAssetId)
{
	if (LoadedAssetId.IsValid())
	{
		UAssetManager& AssetManager = UAssetManager::Get();
		UPDA_Dice* DiceData = Cast<UPDA_Dice>(AssetManager.GetPrimaryAssetObject(LoadedAssetId));
		
		// Now that the assets are loaded, retrieve them
		TSubclassOf<ADiceActor> DiceClass = DiceData->DiceClass.Get();
		UStaticMesh* DiceMesh = DiceData->DiceMesh.Get();
		UMaterialInterface* DiceMaterial = DiceData->DiceMaterial.Get(); // May be nullptr

        if (DiceClass && DiceMesh)
        {
            // Use a default material if DiceMaterial is not set in the data asset
            if (!DiceMaterial)
            {
                // Load or find a default material
                DiceMaterial = LoadObject<UMaterialInterface>(nullptr, TEXT("/Game/DefaultPath/DefaultMaterial.DefaultMaterial"));
                if (!DiceMaterial)
                {
                    UE_LOG(LogTemp, Warning, TEXT("Default material could not be found or loaded."));
                }
            }

            // Random spawn location within the box
            FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
            FRotator SpawnRotation = UKismetMathLibrary::RandomRotator(true);

            // Spawn the dice actor in a deferred state
            ADiceActor* SpawnedDiceActor = GetWorld()->SpawnActorDeferred<ADiceActor>(DiceClass, FTransform(SpawnRotation, SpawnLocation));

            if (SpawnedDiceActor)
            {
                // Assign the loaded data to the dice actor
                SpawnedDiceActor->DiceId = LoadedAssetId;
                SpawnedDiceActor->DiceMeshComponent->SetStaticMesh(DiceMesh);

                // Set the material if valid
                if (DiceMaterial)
                {
                    SpawnedDiceActor->DiceMeshComponent->SetMaterial(0, DiceMaterial);
                }

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
            UE_LOG(LogTemp, Warning, TEXT("Failed to load dice class or mesh asynchronously."));
        }
    }
}

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
			const FVector NewLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
			const FRotator NewRotation = UKismetMathLibrary::RandomRotator(true);

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
    	DiceResultsMap.Remove(Die);
 
		Die->HandleEndCursorOver(nullptr);
		
		const FVector NewLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
		const FRotator NewRotation = UKismetMathLibrary::RandomRotator(true);

		Die->SetActorLocationAndRotation(NewLocation, NewRotation, false, nullptr, ETeleportType::TeleportPhysics);
		Die->DiceMeshComponent->WakeRigidBody(NAME_None);

		const FVector LaunchDirection = DebugArrow->GetForwardVector();
		Die->DiceMeshComponent->AddImpulse(LaunchDirection * LaunchForce, NAME_None, true);

		const FVector Torque = FVector::UpVector * FMath::RandRange(1000.0f, 2000.0f); 
		Die->DiceMeshComponent->AddTorqueInRadians(Torque, NAME_None, true);

		Die->SetDieState(EDieState::Rolling);
	}
}

void ADiceThrower::OnDiceResult(ADiceActor* Die, const FText& Result)
{
	// Convert the result to a string
	const FString ResultString = Result.ToString();

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
	DiceArray.Empty();
	
	// Broadcast that all dice have been cleared
	OnDiceCleared.Broadcast();
}

void ADiceThrower::AddDice(const FPrimaryAssetId DiceId)
{
	if (!HasAuthority())
	{
		Server_AddDice(DiceId);
		return;
	}

	if (DiceId.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("✅ Server: Adding Dice: %s"), *DiceId.ToString());
		DiceArray.Add(DiceId);
	}
}

void ADiceThrower::RemoveDice(const FPrimaryAssetId DiceId)
{
	if (!HasAuthority())
	{
		Server_RemoveDice(DiceId);
		return;
	}

	if (DiceId.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("✅ Server: Removing Dice: %s"), *DiceId.ToString());
		DiceArray.RemoveSingle(DiceId);
	}
}


void ADiceThrower::Server_AddDice_Implementation(const FPrimaryAssetId DiceId)
{
	AddDice(DiceId);
}

bool ADiceThrower::Server_AddDice_Validate(const FPrimaryAssetId DiceId)
{
	return true;
}

void ADiceThrower::Server_RemoveDice_Implementation(const FPrimaryAssetId DiceId)
{
	RemoveDice(DiceId);
}

bool ADiceThrower::Server_RemoveDice_Validate(const FPrimaryAssetId DiceId)
{
	return true;
}
