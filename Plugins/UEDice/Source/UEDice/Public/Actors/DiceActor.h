/** This project is distributed "as is," without warranty of any kind, express or implied,
 * including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceActor.generated.h"

class UPDA_Dice;
class ADiceDecal;
/**
 * A visual actor representation of a die.
 */

UENUM(BlueprintType)
enum class EDieState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Rolling UMETA(DisplayName = "Rolling"),
	Stopped UMETA(DisplayName = "Stopped"),
	Invalid UMETA(DisplayName = "Invalid")
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDieResult,  ADiceActor*, Die, const FText&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDieStateChanged, ADiceActor*, Die,  const EDieState&, NewDieState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieHover,  ADiceActor*, Die );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieHoverEnd,  ADiceActor*, Die );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieClicked,  ADiceActor*, Die);

UCLASS(BlueprintType)
class UEDICE_API ADiceActor : public AActor
{
	GENERATED_BODY()
	

public:
	/** Sets default values for this actor's properties */
	ADiceActor();
	
	UFUNCTION(BlueprintPure, Category = "Dice")
	EDieState GetDieState() const;

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void SetDieState(const EDieState NewDieState) ;

	/** Event handler for mouse hover start */
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleBeginCursorOver(UPrimitiveComponent* TouchedComponent);

	/** Event handler for mouse hover end */
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleEndCursorOver(UPrimitiveComponent* TouchedComponent);

	/** Event handler for mouse hover end */
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void HandleOnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);
	
	/** Static mesh component for visualizing the dice */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
	UStaticMeshComponent* DiceMeshComponent;

	/** The data asset for this dice */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	FPrimaryAssetId DiceId;

	/** Dice Decal */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TSoftClassPtr<ADiceDecal> DiceDecal;	
	
	/** Initialize the dice actor based on the data asset */
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void InitializeDice();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* DiceHitSound;
	
	/** Event dispatcher for broadcasting the dice result */
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieResult OnDieResult;

	/** Event dispatcher for broadcasting when the result has changed. */
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieStateChanged OnDieStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieHover OnDieHover;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieHoverEnd OnDieHoverEnd;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieClicked OnDieClicked;
	
protected:
	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

private:
	/** Handler for when the physics simulation goes to sleep */
	UFUNCTION()
	void HandlePhysicsSleep(UPrimitiveComponent* SleepingComponent, FName BoneName);

	UFUNCTION()
	void HandleOnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	/** Calculate the dice result based on the up face */
	FText CalculateDiceResult() const;

	/** Check if we got a valid dice result, eg: the dice didn't stop correctly. */
	bool CheckValidity() const;
	
	/** Pointer to the currently spawned decal (to track whether it's spawned) */
	TWeakObjectPtr<ADiceDecal> SpawnedDecal;
	
	/** The internal DieState */
	EDieState DieState;
};
