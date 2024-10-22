#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceActor.generated.h"

class UPDA_Dice;
class ADiceDecal;
/**
 * A visual actor representation of a dice.
 */

UENUM(BlueprintType)
enum class EDieState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Rolling UMETA(DisplayName = "Rolling"),
	Stopped UMETA(DisplayName = "Stopped"),
	Invalid UMETA(DisplayName = "Invalid")
};


UCLASS(BlueprintType)
class UEDICE_API ADiceActor : public AActor
{
	GENERATED_BODY()
	
	// Delegate signature for broadcasting dice result
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDieResult, ADiceActor*, Die,  FText, Result);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDieStateChanged,ADiceActor*, Die,  EDieState, NewDieState);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieHover, ADiceActor*, Die );
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieHoverEnd, ADiceActor*, Die );
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieClicked, ADiceActor*, Die);
	
public:
	// Sets default values for this actor's properties
	ADiceActor();

	// Called when an instance of this class is constructed (editor or runtime)
	virtual void OnConstruction(const FTransform& Transform) override;

	UFUNCTION(BlueprintPure, Category = "Dice")
	EDieState GetDieState() const;

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void SetDieState(const EDieState NewDieState) ;

	// Event handler for mouse hover start
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleBeginCursorOver(UPrimitiveComponent* TouchedComponent);

	// Event handler for mouse hover end
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleEndCursorOver(UPrimitiveComponent* TouchedComponent);

	// Event handler for mouse hover end
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleOnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);
	
	// Static mesh component for visualizing the dice
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
	UStaticMeshComponent* DiceMeshComponent;

	// The data asset for this dice
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TSoftObjectPtr<UPDA_Dice> DiceData;

	// Dice Decal
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TSoftClassPtr<ADiceDecal> DiceDecal;	
	
	// Initialize the dice actor based on the data asset
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void InitializeDice();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* DiceHitSound;
	
	// Event dispatcher for broadcasting the dice result
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieResult OnDieResult;

	// Event dispatcher for broadcasting when the result has changed.
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieStateChanged OnDieStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieHover OnDieHover;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieHoverEnd OnDieHoverEnd;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieClicked OnDieClicked;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Handler for when the physics simulation goes to sleep
	UFUNCTION()
	void HandlePhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);

	UFUNCTION()
	void HandleOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	// Calculate the dice result based on the up face
	FText CalculateDiceResult() const;

	// Check if we got a valid dice result, eg: the dice didn't stop correctly.
	bool CheckValidity() const;


	
	// Pointer to the currently spawned decal (to track whether it's spawned)
	TWeakObjectPtr<ADiceDecal> SpawnedDecal;

	
	// The internal DieState
	EDieState DieState;
	
};
