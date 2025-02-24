// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Controller/DicePlayerState.h"
#include "EngineUtils.h" 
#include "Actors/DiceThrower.h"

void ADicePlayerState::Server_RequestSpawnDice_Implementation()
{
	if (CachedDiceThrower)
	{
		CachedDiceThrower->Server_SpawnDice();
	}
}

bool ADicePlayerState::Server_RequestSpawnDice_Validate()
{
	return true;
}

void ADicePlayerState::BeginPlay()
{
	Super::BeginPlay();
	
	for (TActorIterator<ADiceThrower> It(GetWorld()); It; ++It)
	{ 
		CachedDiceThrower = *It;
		break;
	}
}
