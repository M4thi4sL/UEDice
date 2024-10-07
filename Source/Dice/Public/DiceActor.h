#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceActor.generated.h"

class UPDA_Dice;

/**
 * A visual actor representation of a dice.
 */
UCLASS()
class DICE_API ADiceActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADiceActor();

	// Called when an instance of this class is constructed (editor or runtime)
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// The data asset for this dice
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TSoftObjectPtr<UPDA_Dice> DiceData;

	// Initialize the dice actor based on the data asset
	void InitializeDice();

	// Delegate signature for broadcasting dice result
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDiceResult, FString, Result);

	// Event dispatcher for broadcasting the dice result
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDiceResult OnDiceResult;

private:
	// Callback when DiceData is loaded
	void OnDiceDataLoaded();

	// Callback when DiceMesh is loaded
	void OnDiceMeshLoaded();

	// Handler for when the physics simulation goes to sleep
	UFUNCTION()
	void HandlePhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);

	// Static mesh component for visualizing the dice
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DiceMeshComponent;

	// Calculate the dice result based on the up face
	FString CalculateDiceResult() const;
};
