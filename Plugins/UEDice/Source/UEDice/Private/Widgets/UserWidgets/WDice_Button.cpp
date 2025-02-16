// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Widgets/UserWidgets/WDice_Button.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UWDice_Button::NativeConstruct()
{
	Super::NativeConstruct();

	if (Button)
	{
		Button->OnClicked.AddDynamic(this, &UWDice_Button::HandleButtonClicked);
	}
}

void UWDice_Button::InitializeWidget_Implementation()
{
	Super::InitializeWidget_Implementation();

	if (ButtonText)
	{
		ButtonText->SetText(Text);
		ButtonText->SetFont(FontInfo);
	}
}

void UWDice_Button::HandleButtonClicked()
{
	if (OnButtonClicked.IsBound())
	{
		OnButtonClicked.Broadcast(this);
	}
}
