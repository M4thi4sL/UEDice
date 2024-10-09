// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "StringUtils.h"

FString UStringUtils::PadInteger(int32 Number, int32 MinWidth, const FString& PaddingChar)
{
	// Ensure the padding character is valid and has only one character
	FString ValidPaddingChar = PaddingChar.IsEmpty() ? TEXT("0") : PaddingChar.Left(1);

	// Convert the integer to string
	FString NumberStr = FString::FromInt(Number);
	int32 NumLength = NumberStr.Len();

	// If padding is needed, calculate and apply the padding
	if (NumLength < MinWidth)
	{
		int32 PaddingAmount = MinWidth - NumLength;
		FString Padding = FString::ChrN(PaddingAmount, ValidPaddingChar[0]);
		return Padding + NumberStr;
	}

	return NumberStr;
}
