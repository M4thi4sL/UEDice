// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_ServerIndicator.generated.h"

class UTextBlock;
/**
 * c++ class that allows to identify and display what netmode we are in
 */
UCLASS()
class UEDICE_API UWDice_ServerIndicator : public UWDiceUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
    UPROPERTY(meta = (BindWidget))
	UTextBlock* Netmode;

	void UpdateRoleText();
};
