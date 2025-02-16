// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Actors/DiceActor.h"
#include "Actors/DiceThrower.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_Controls.generated.h"

enum class EDieState : uint8;
class ADiceActor;
class ADiceThrower;
class UWDice_Die;
class UWDice_DieSelector;
class UWDice_Tally;
class UWDice_Button;

/**
 * c++ base class for the Control panel of the DemoScene.
 * Connects the individual widgets together and handels their layout.
 */
UCLASS()
class UEDICE_API UWDice_Controls : public UWDiceUserWidget
{
	GENERATED_BODY()

public:
	
protected:

	UPROPERTY(meta = (BindWidget))
	UWDice_Tally* Tally;

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* DiceBox;

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* DieButtonsBox;

	UPROPERTY(meta = (BindWidget))
	UWDice_Button* BtnSpawnDice;

	UPROPERTY(meta = (BindWidget))
	UWDice_Button* BtnRollDice;

	UPROPERTY(meta = (BindWidget))
	UWDice_Button* BtnClearDice;
	
	UPROPERTY(meta = (BindWidget))
	UWDice_Button* BtnResetDice;
	
	UPROPERTY(BlueprintReadWrite)
	TMap<ADiceActor*, UWDice_Die*> DiceMap;

	UPROPERTY(BlueprintReadWrite)
	ADiceThrower* DiceThrower;

	/** What widget should we use when spawning DieSelectors? This is usually a blueprint derived childclass */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Dice" )
	TSubclassOf<UWDice_DieSelector> WDieSelector;

	/** What widget should we use when spawning DieWidgets? This is usually a blueprint derived childclass */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Dice" )
	TSubclassOf<UWDice_Die> WDie;
	
	virtual void NativeConstruct() override;
	virtual void InitializeWidget_Implementation() override;
	
	/** Dicethrower delegates */
	UFUNCTION(BlueprintCallable, category = "Delegates|DiceThrower")
	void OnDieSpawned(ADiceActor* SpawnedDie);

	UFUNCTION(BlueprintCallable, category = "Delegates|DiceThrower")
	void OnDiceCleared();
 
	UFUNCTION(BlueprintCallable, category = "Delegates|DiceThrower")
	void OnTotalResultChanged(const FText& NewText );
 
	/** Dice delegates */
	UFUNCTION(BlueprintCallable, category = "Delegates|Die")
	void OnDieStateChanged(ADiceActor* Die, const EDieState& NewDieState);

	UFUNCTION(BlueprintCallable, category = "Delegates|Die")
	void OnDieResult(ADiceActor* Die, const FText& NewResult);

	UFUNCTION(BlueprintCallable, category = "Delegates|Die")
	void OnDieHover(ADiceActor* Die);

	UFUNCTION(BlueprintCallable, category = "Delegates|Die")
	void OnDieHoverEnd(ADiceActor* Die);

	/** Widget */
	UFUNCTION(BlueprintCallable, category = "Delegates|Die")
	void OnDieAdded(FPrimaryAssetId Die);

	UFUNCTION(BlueprintCallable, category = "Delegates|Die")
	void OnDieRemoved(FPrimaryAssetId Die);

	/** Die Widget */
	UFUNCTION(BlueprintCallable, category = "Delegates|DieWidget")
	void OnDieWidgetHover( UWDice_Die* DieWidget);

	UFUNCTION(BlueprintCallable, category = "Delegates|DieWidget")
	void OnDieWidgetHoverEnd(UWDice_Die* DieWidget);

	UFUNCTION(BlueprintCallable, category = "Delegates|DieWidget")
	void OnDieWidgetClicked (UWDice_Die* DieWidget);

private:

	UPROPERTY()
	TArray<UWDice_DieSelector*> DiceSelectors;

	UFUNCTION()
	void HandleSpawnDicePressed(UWDiceUserWidget* Widget);

	UFUNCTION()
	void HandleClearDicePressed(UWDiceUserWidget* Widget);

	UFUNCTION()
	void HandleResetDicePressed(UWDiceUserWidget* Widget);

	UFUNCTION()
	void HandleRollDicePressed(UWDiceUserWidget* Widget);
	
};

