// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_DieSelector.generated.h"

class UTextBlock;
class UButton;
class UImage;
class UPDA_Dice;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddDice, const FPrimaryAssetId, DiceToAdd );
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoveDice, const FPrimaryAssetId, DiceToRemove);


/**
 * c++ base class for the Die selector.
 * Displays information about the die data-asset and allows the user to increase or decrease its count.
 */
UCLASS()
class UEDICE_API UWDice_DieSelector : public UWDiceUserWidget
{
	GENERATED_BODY()

public:

	/** Add 1 to the current amount */
	UFUNCTION(BlueprintCallable, Category = "DieSelector")
	void IncrementAmount();

	/** Remove 1 from the current amount */
	UFUNCTION(BlueprintCallable, Category = "DiceSelector")
	void DecrementAmount();

	/** Reset the amount to 0 */
	UFUNCTION(BlueprintCallable, Category = "DiceSelector")
	void ResetAmount();

	UFUNCTION(BlueprintCallable, Category = "DiceSelector")
	void SetDieId(const FPrimaryAssetId NewDieId);
	
	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "DiceSelector")
	FOnAddDice OnAddDice;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "DiceSelector")
	FOnRemoveDice OnRemoveDice;

	
	
protected:

	virtual void InitializeWidget_Implementation() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (ExposeOnSpawn))
	FPrimaryAssetId Die;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Amount;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnAdd;

	UPROPERTY(meta = (BindWidget))
	UButton* BtnSub;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Count;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;
	
	UPROPERTY(meta = (BindWidget))
	UImage* Image;

private:
	UFUNCTION()
	void UpdateCountText() const;
};
