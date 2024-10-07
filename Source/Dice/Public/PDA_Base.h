// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PDA_Base.generated.h"

/**
 * 
 */
UCLASS()
class DICE_API UPDA_Base : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	// Thumbnail for the item
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	TSoftObjectPtr<UTexture> Icon;
	
	// Name for the name.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FText Name;

	// The description for this item.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setup")
	FText Description;
};
