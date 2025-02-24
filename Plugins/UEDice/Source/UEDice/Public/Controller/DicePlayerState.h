// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DicePlayerState.generated.h"

class ADiceThrower;

/**
 * c++ baseclass for the playerstate
 */
UCLASS()
class UEDICE_API ADicePlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY()
	ADiceThrower* CachedDiceThrower;

public:
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_RequestSpawnDice();

};
