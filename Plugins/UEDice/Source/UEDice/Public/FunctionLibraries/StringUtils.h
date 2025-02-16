/** This project is distributed "as is," without warranty of any kind, express or implied,
 * including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StringUtils.generated.h"

/**
 * c++ function library that handles exclusively string objects
 */
UCLASS()
class UEDICE_API UStringUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	// Convert a given integer to String and pad it with the given character if necessary.
	UFUNCTION(BlueprintPure, Category = "StringUtilities")
	static FString PadInteger(const int32 Number, const int32 MinWidth, const FString& PaddingChar);

	/** Converts an enum value to a clean display name (removes namespace) */
	UFUNCTION(BlueprintPure, Category = "Enum", meta = (CompactNodeTitle = "EnumToText", BlueprintAutocast))
	static FText GetEnumAsText(const UEnum* EnumType, uint8 EnumValue);
    
	/** Overload to allow passing enum directly */
	template <typename T>
	static FText GetEnumAsText(T EnumValue)
	{
		return GetEnumAsText(StaticEnum<T>(), static_cast<uint8>(EnumValue));
	}
};
