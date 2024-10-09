// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StringUtils.generated.h"

/**
 * 
 */
UCLASS()
class DICE_API UStringUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// Convert a given integer to String and pad it with the given character if necessary.
	UFUNCTION(BlueprintPure, Category = "StringUtilities")
	static FString PadInteger(int32 Number, int32 MinWidth, const FString& PaddingChar);
};
