/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WDiceUserWidget.generated.h"

/**
 * c++ base class for the Dice UI elements
 */
UCLASS()
class UEDICE_API UWDiceUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;

	/** Override this function to do the initial setup of the widget.
	 * This function gets called during pre-construct (design time) and OnConstruct.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Dice")
	void InitializeWidget();
};
