#include "DiceThrower.h"
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
	
	// Spawn and launch dice separately
	SpawnDice();
	//LaunchDice();
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
				SpawnedDiceActor->OnDiceResult.AddDynamic(this, &ADiceThrower::OnDiceResult);
				SpawnedDice.Add(SpawnedDiceActor);
				
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
	}
}


// Called when a dice broadcasts its result
void ADiceThrower::OnDiceResult(FString Result)
{
	// Convert result to an integer and add to the total
	int32 DiceValue = FCString::Atoi(*Result);
	TotalResult += DiceValue;

	UE_LOG(LogTemp, Log, TEXT("Received Dice Result: %s, Total so far: %d"), *Result, TotalResult);
}

// Reset and delete all spawned dice
void ADiceThrower::ResetDice()
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

	UE_LOG(LogTemp, Log, TEXT("All spawned dice have been reset and destroyed."));
}
