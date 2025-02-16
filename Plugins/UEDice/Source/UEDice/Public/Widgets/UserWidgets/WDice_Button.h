// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_Button.generated.h"

class UButton;
class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClicked, UWDiceUserWidget*, Widget);

/**
 * c++ baseclass for a Dice button, any clickable element most likely derives from this button.
 */
UCLASS()
class UEDICE_API UWDice_Button : public UWDiceUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Dice")
	FOnButtonClicked OnButtonClicked;
	
protected:

	virtual void NativeConstruct() override;
	virtual void InitializeWidget_Implementation() override;
	
	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button", meta = (ExposeOnSpawn))
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Button")
	FSlateFontInfo FontInfo;

private:
	UFUNCTION()
	void HandleButtonClicked();

};
