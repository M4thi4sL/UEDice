// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_Die.generated.h"

enum class EDieState : uint8;
class UTextBlock;
class UImage;
class UBorder;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieWidgetHovered, UWDice_Die*, DieWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieWidgetHoveredEnd, UWDice_Die*, DieWidget);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDieWidgetClicked, UWDice_Die*, DieWidget);

/**
 * c++ baseclass for the die widget.
 * This widget shows the status of the current die as well as its result.
 * Hovering over it highlights the die in the world.
 * Clicking it re-throws the die
 */
UCLASS()
class UEDICE_API UWDice_Die : public UWDiceUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void UpdateDieStatus(const FText& NewDieStatus);

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void UpdateDieState(const EDieState& NewDieState);

	UFUNCTION(BlueprintCallable, Category = "Dice")
	void UpdateDieResult(const FText& NewResult);

	UFUNCTION(BlueprintCallable)
	void SetHover(const bool bIsHovered) const ;

	UFUNCTION(BlueprintCallable)
	void SetDieId(const FPrimaryAssetId NewDieId);
	
	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Dice")
	FOnDieWidgetClicked OnDieWidgetClicked;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Dice")
	FOnDieWidgetHovered OnDieWidgetHovered;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, Category = "Dice")
	FOnDieWidgetHoveredEnd OnDieWidgetHoveredEnd;


	
protected:

	virtual void InitializeWidget_Implementation() override;
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	UPROPERTY(BlueprintReadWrite, Category = "Die")
	FPrimaryAssetId Die;

	UPROPERTY(meta = (BindWidget))
	UImage* Invalid;

	UPROPERTY(meta = (BindWidget))
	UBorder* Border;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Result;

	UPROPERTY(meta = (BindWidget))
	UImage* Icon;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Name;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Score;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Status;

	
private:

};
