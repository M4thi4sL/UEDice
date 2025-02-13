/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */


#include "FunctionLibraries/StringUtils.h"

FString UStringUtils::PadInteger(const int32 Number, const int32 MinWidth, const FString& PaddingChar)
{
	FString ValidPaddingChar = PaddingChar.IsEmpty() ? TEXT("0") : PaddingChar.Left(1);
	FString NumberStr = FString::FromInt(Number);
	
	/** Apply padding if string lenght is less than desired width */
	if (const int32 NumLength = NumberStr.Len() < MinWidth)
	{
		const int32 PaddingAmount = MinWidth - NumLength;
		const FString Padding = FString::ChrN(PaddingAmount, ValidPaddingChar[0]);
		return Padding + NumberStr;
	}

	return NumberStr;
}
