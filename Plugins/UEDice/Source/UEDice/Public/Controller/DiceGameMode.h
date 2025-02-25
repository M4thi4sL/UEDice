// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DiceGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UEDICE_API ADiceGameMode : public AGameMode
{
	GENERATED_BODY()


public:
	ADiceGameMode();
	
	// Predetermined list of colors to cycle through.
	UPROPERTY(EditDefaultsOnly, Category = "Appearance")
	TArray<FLinearColor> PredeterminedColors;

protected:
	// Override PostLogin to assign colors to players.
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
