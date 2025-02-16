// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_Overlay.generated.h"

/**
 * c++ base class for the DiceOveraly.
 * This is a pretty dumb widget as its main purpose is layouting the other elements on the screen.
 */
UCLASS()
class UEDICE_API UWDice_Overlay : public UWDiceUserWidget
{
	GENERATED_BODY()
};
