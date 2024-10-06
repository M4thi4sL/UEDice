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
	
	// The data asset for this dice
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TSoftObjectPtr<UPDA_Dice> DiceData;

	// Initialize the dice actor based on the data asset
	void InitializeDice();
	
	// Static mesh component for visualizing the dice
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* DiceMeshComponent;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:
	// Callback when DiceData is loaded
	void OnDiceDataLoaded();

	// Callback when DiceMesh is loaded
	void OnDiceMeshLoaded();


};
