// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/WDiceUserWidget.h"
#include "WDice_Tally.generated.h"

class UTextBlock;
/**
 * c++ base class for the Tally widget. This widget displays information about the
 * dice in-play and their results.
 */
UCLASS()
class UEDICE_API UWDice_Tally : public UWDiceUserWidget
{
	GENERATED_BODY()

public:

	/**  Clear the values of the text blocks */
	UFUNCTION(BlueprintCallable, Category = "Tally")
	void Clear() const;

	/** Update the value of the dice textblock */
	UFUNCTION(BlueprintCallable, Category = "Tally")
	void SetDiceNumber(const FText& NewTotal ) const;

	/** Update the value of the score textblock */
	UFUNCTION(BlueprintCallable, Category = "Tally")
	void SetScoreTotal(const FText& NewTotal) const;
	
protected:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Total;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* Score;
};
