// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Controller/DiceGameMode.h"

#include "Controller/DicePlayerState.h"
#include "GameFramework/GameStateBase.h"

ADiceGameMode::ADiceGameMode()
{
	// Populate your list with the colors you want.
	PredeterminedColors.Add(FLinearColor::Red);
	PredeterminedColors.Add(FLinearColor::Green);
	PredeterminedColors.Add(FLinearColor::Blue);
	PredeterminedColors.Add(FLinearColor::Yellow);
}

void ADiceGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	// Get the player's PlayerState
	if (NewPlayer && NewPlayer->PlayerState)
	{
		ADicePlayerState* DicePS = Cast<ADicePlayerState>(NewPlayer->PlayerState);
		if (DicePS && PredeterminedColors.Num() > 0)
		{
			// Use the player's unique index or the current number of players to pick a color.
			int32 PlayerIndex = GameState->PlayerArray.Num() - 1;
			//DicePS->PlayerDecalColor = PredeterminedColors[PlayerIndex % PredeterminedColors.Num()];
		}
	}
}