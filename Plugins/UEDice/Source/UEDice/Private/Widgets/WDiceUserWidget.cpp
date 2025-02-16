// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Widgets/WDiceUserWidget.h"

void UWDiceUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	InitializeWidget();
}

void UWDiceUserWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (IsDesignTime()) InitializeWidget();
}

void UWDiceUserWidget::InitializeWidget_Implementation()
{
	/** overriden in child classes as every child widget would mostly require a different setup */
}
