// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DiceSubSystem.generated.h"

/**
 * c++ baseclass that keeps track of every dice thrower, its dice and their results.
 * Contains multiple useful getters to get results back. 
 */
UCLASS()
class UEDICE_API UDiceSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
};
