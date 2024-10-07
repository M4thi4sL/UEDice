#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceThrower.generated.h"

class UPDA_Dice;
class ADiceActor;
class UBoxComponent;
class UArrowComponent;

UCLASS()
class DICE_API ADiceThrower : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ADiceThrower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	virtual void OnConstruction(const FTransform& Transform) override;

	// Function to spawn dice
	UFUNCTION(BlueprintCallable,CallInEditor, Category = "Dice")
	void SpawnDice();

	// Function to launch all spawned dice
	UFUNCTION(BlueprintCallable,CallInEditor, Category = "Dice")
	void LaunchDice();

	// Function to launch a single die
	UFUNCTION(BlueprintCallable,CallInEditor, Category = "Dice")
	void LaunchDie(ADiceActor* Die);

	// Function to reset and delete all spawned dice
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void ResetDice();
	
	// The arrow component for visualizing the throw direction
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	UArrowComponent* DebugArrow;

	// Box component for visualizing the spawn area
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	UBoxComponent* SpawnBox;
	
	// Array of dice data assets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TArray<UPDA_Dice*> DiceArray;

	// Force applied to launch the dice
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	float LaunchForce = 1000.0f;

	// Box extent for spawning dice
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	FVector SpawnBoxExtent = FVector(50.0f, 50.0f, 50.0f);




private:
	// Called when a dice broadcasts its result
	UFUNCTION()
	void OnDiceResult(FString Result);

	// Array of spawned dice actors
	TArray<ADiceActor*> SpawnedDice;

	// Sum of all results
	int32 TotalResult = 0;
};
