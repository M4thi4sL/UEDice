#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceThrower.generated.h"

enum class EDieState : uint8;
class UPDA_Dice;
class ADiceActor;
class UBoxComponent;
class UArrowComponent;

UCLASS()
class UEDICE_API ADiceThrower : public AActor
{
	GENERATED_BODY()

	// Declare various dynamic multicast delegates for broadcasting events
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieThrown, ADiceActor*, ThrownDie);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieSpawned, ADiceActor*, SpawnedDie);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDiceCleared);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTotalChanged, FText, NewResult);

public:
	// Sets default values for this actor's properties
	ADiceThrower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void OnConstruction(const FTransform& Transform) override;

	// Function to spawn dice
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void SpawnDice();

	// Function to launch a single die
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void LaunchDie(ADiceActor* Die);

	// Reroll the existing spawned dice.
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void RerollAll();

	// Reroll the existing spawned dice.
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void RerollDice(ADiceActor* Die);
	
	
	// Function to reset and delete all spawned dice
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void ClearDice();

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void AddDice(UPDA_Dice* Dice);

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void RemoveDice(UPDA_Dice* Dice);

	// Event that will broadcast when a die is thrown
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieThrown OnDieThrown;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDiceCleared OnDiceCleared;

	// Event dispatcher for broadcasting a new total result of the dice
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnTotalChanged OnResultChanged;

	// Event that will broadcast when a die is spawned
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieSpawned OnDieSpawned;

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
	float LaunchForce = 100.0f;

	// Box extent for spawning dice
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	FVector SpawnBoxExtent = FVector(5.0f, 10.0f, 5.0f);

private:
	// Called when a dice broadcasts its result
	UFUNCTION()
	void OnDiceResult(ADiceActor* Die, FText Result);

	UFUNCTION()
	void OnDieClicked( ADiceActor* Die);
	
	// Array of spawned dice actors
	TArray<ADiceActor*> SpawnedDice;
	
	// Map to keep track of the dices and their values.
	TMap<ADiceActor*, FString> DiceResultsMap;

	// Asynchronous callback when assets are loaded
	void OnAssetsLoaded(UPDA_Dice* DiceData);
};
