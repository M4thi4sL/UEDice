/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceThrower.generated.h"

enum class EDieState : uint8;
class UPDA_Dice;
class ADiceActor;
class UBoxComponent;
class UArrowComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieThrown, ADiceActor*, ThrownDie);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieSpawned, ADiceActor*, SpawnedDie);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDiceCleared);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTotalChanged, const FText&, NewResult);

UCLASS()
class UEDICE_API ADiceThrower : public AActor
{
	GENERATED_BODY()

public:
	ADiceThrower();

	/** Event that will broadcast when a die is thrown */
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieThrown OnDieThrown;

	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDiceCleared OnDiceCleared;

	/** Event dispatcher for broadcasting a new total result of the dice */
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnTotalChanged OnResultChanged;

	/** Event that will broadcast when a die is spawned */
	UPROPERTY(BlueprintAssignable, Category = "Dice")
	FOnDieSpawned OnDieSpawned;

	/** Function to spawn dice */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void SpawnDice();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SpawnDice();

	UFUNCTION(NetMulticast, Reliable)
	void Multicast_SpawnDice(ADiceActor* SpawnedDie);
	
	/** Function to launch a single die */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void LaunchDie(ADiceActor* Die);
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_LaunchDie(ADiceActor* Die);

	
	/** Reroll the existing spawned dice. */
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void RerollAll();

	/** Reroll the existing spawned dice.*/
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void RerollDice(ADiceActor* Die);

	/** Function to reset and delete all spawned dice*/
	UFUNCTION(BlueprintCallable, CallInEditor, Category = "Dice")
	void ClearDice();

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void AddDice(const FPrimaryAssetId DiceId);

	UFUNCTION(Server,Reliable, WithValidation, Category = "Dice")
	void Server_AddDice(const FPrimaryAssetId DiceId);
	
	UFUNCTION(BlueprintCallable, Category = "Dice")
	void RemoveDice(const FPrimaryAssetId DiceId);

	UFUNCTION(Server, Reliable, WithValidation, Category = "Dice")
	void Server_RemoveDice(const FPrimaryAssetId DiceId);
	
protected:
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	
	/** The arrow component for visualizing the throw direction*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	UArrowComponent* DebugArrow;

	/** Box component for visualizing the spawn area*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Debug")
	UBoxComponent* SpawnBox;

	/** Array of dice data assets*/
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = "Dice")
	TArray<FPrimaryAssetId> DiceArray;

	/** Force applied to launch the dice*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	float LaunchForce = 100.0f;

	/** Box extent for spawning dice*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dice")
	FVector SpawnBoxExtent = FVector(5.0f, 10.0f, 5.0f);
	
	UPROPERTY(Replicated)
	TArray<ADiceActor*> SpawnedDice;
private:

	UFUNCTION()
	void OnDiceResult(ADiceActor* Die, const FText& Result);

	UFUNCTION()
	void OnDieClicked( ADiceActor* Die);
	
	/** Map to keep track of the dices and their values.*/
	TMap<ADiceActor*, FString> DiceResultsMap;

	/** Asynchronous callback when assets are loaded */
	void OnAssetsLoaded(const FPrimaryAssetId&  LoadedAssetId);
};
