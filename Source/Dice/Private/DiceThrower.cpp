#include "DiceThrower.h"

#include <string>

#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "PDA_Dice.h"
#include "DiceActor.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"

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

void ADiceThrower::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	SpawnBox->SetBoxExtent(SpawnBoxExtent);
}

// Spawn all dice specified in the DiceArray
void ADiceThrower::SpawnDice()
{
	// Iterate over each dice data asset
	for (UPDA_Dice* DiceData : DiceArray)
	{
		if (DiceData)
		{
			// Load the DiceActor class from the soft reference
			TSubclassOf<ADiceActor> DiceClass = DiceData->DiceClass.LoadSynchronous();
			if (DiceClass)
			{
				// Random spawn location within the box
				FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), SpawnBoxExtent);
				FRotator SpawnRotation = UKismetMathLibrary::RandomRotator(true);

				// Spawn the dice actor in a deferred state
				ADiceActor* SpawnedDiceActor = GetWorld()->SpawnActorDeferred<ADiceActor>(DiceClass, FTransform(SpawnRotation, SpawnLocation));
				SpawnedDiceActor->DiceData = DiceData;
				SpawnedDiceActor->FinishSpawning(FTransform(SpawnRotation, SpawnLocation));

				// Wake up the physics body to ensure it's ready for an impulse
				SpawnedDiceActor->DiceMeshComponent->WakeRigidBody(NAME_None);
				
				// Bind to the OnDiceResult event
				SpawnedDiceActor->OnDieResult.AddDynamic(this, &ADiceThrower::OnDiceResult);
				SpawnedDice.Add(SpawnedDiceActor);

				OnDieSpawned.Broadcast(SpawnedDiceActor);
				
				LaunchDie(SpawnedDiceActor);

			}
		}
	}
}

// Launch all spawned dice
void ADiceThrower::LaunchDice()
{
	// Iterate over all spawned dice and apply an impulse
	for (ADiceActor* SpawnedDiceActor : SpawnedDice)
	{
		if (SpawnedDiceActor)
		{
			// Launch the dice in the direction of the arrow with specified force
			FVector LaunchDirection = DebugArrow->GetForwardVector();
			SpawnedDiceActor->DiceMeshComponent->AddImpulse(LaunchDirection * LaunchForce, NAME_None, true);
			SpawnedDiceActor->SetDieState(EDieState::Rolling);
		}
	}
}

void ADiceThrower::LaunchDie(ADiceActor* Die)
{
	if (Die)
	{
		// Launch the die in the direction of the arrow with specified force
		FVector LaunchDirection = DebugArrow->GetForwardVector();
		Die->DiceMeshComponent->AddImpulse(LaunchDirection * LaunchForce, NAME_None, true);

		//broadcast  a die got thrown.
		OnDieThrown.Broadcast(Die);

	}
}


// Called when a dice broadcasts its result
void ADiceThrower::OnDiceResult(ADiceActor* Die, FText Result)
{
	// Variables to store numeric and non-numeric results
	TArray<FString> NonNumericResults;

	// Check if the FName result is numeric
	FString ResultString = Result.ToString();
	if (ResultString.IsNumeric())
	{
		// Convert to an integer and add to the total
		int32 DiceValue = FCString::Atoi(*ResultString);
		TotalResult += DiceValue;
	}
	else
	{
		// Store non-numeric result in an array
		NonNumericResults.Add(ResultString);
	}

	// Format the result as "total, non-numeric values"
	FString FinalResult;
    
	if (TotalResult > 0)
	{
		// Start with the total result
		FinalResult = FString::FromInt(TotalResult);
	}

	if (NonNumericResults.Num() > 0)
	{
		// Add the non-numeric values, separated by commas
		if (TotalResult > 0)
		{
			FinalResult += ", ";
		}
		FinalResult += FString::Join(NonNumericResults, TEXT(", "));
	}

	// Convert the final result to FText
	FText FinalResultText = FText::FromString(FinalResult);

	// Broadcast the formatted result
	OnResultChanged.Broadcast(FinalResultText);

	// Log the result and total so far
	UE_LOG(LogTemp, Log, TEXT("Formatted Dice Result: %s"), *FinalResult);
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

	// Reset the total result
	TotalResult = 0;

	//Broadcast we have cleared the spawned dice.
	OnDiceCleared.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("All spawned dice have been reset and destroyed."));
}

