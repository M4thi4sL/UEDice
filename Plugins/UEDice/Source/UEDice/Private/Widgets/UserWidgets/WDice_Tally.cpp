// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Widgets/UserWidgets/WDice_Tally.h"

#include "Components/TextBlock.h"

void UWDice_Tally::Clear() const
{
	if (Total && Score)
	{
		Total->SetText(FText::FromString("0"));
		Score->SetText(FText::FromString("0"));
	}
}

void UWDice_Tally::SetDiceNumber(const FText& NewTotal) const
{
	if (Total) Total->SetText(NewTotal);
}

void UWDice_Tally::SetScoreTotal(const FText& NewTotal) const
{
	if (Score) Score->SetText(NewTotal);
}
