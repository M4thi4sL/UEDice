// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Widgets/UserWidgets/WDice_DieSelector.h"

#include "DataAssets/PDA_Dice.h"

#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "FunctionLibraries/StringUtils.h"

void UWDice_DieSelector::IncrementAmount()
{
	Amount++;
	if (OnAddDice.IsBound()) OnAddDice.Broadcast(Die);
	UpdateCountText();
}

void UWDice_DieSelector::DecrementAmount()
{
	Amount--;
	Amount = FMath::Max(Amount, 0);

	if (Amount >= 0)
	{
		if (OnRemoveDice.IsBound()) OnRemoveDice.Broadcast(Die);
	}

	UpdateCountText();
}

void UWDice_DieSelector::ResetAmount()
{
	Amount = 0;
	UpdateCountText();
}

void UWDice_DieSelector::SetDieId(const FPrimaryAssetId NewDieId)
{
	Die = NewDieId;
}

void UWDice_DieSelector::InitializeWidget_Implementation()
{
	Super::InitializeWidget_Implementation();
	
	UAssetManager& AssetManager = UAssetManager::Get();

	if (!Die.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid PrimaryAssetId!"));
		return;
	}

	const FStreamableDelegate LoadCompleteDelegate = FStreamableDelegate::CreateLambda([this]()
	{
		if (const UObject* LoadedAsset = UAssetManager::Get().GetPrimaryAssetObject(Die))
		{
			if (const UPDA_Dice* Die = Cast<UPDA_Dice>(LoadedAsset))
			{
				if (Image && Name)
				{
					Image->SetBrushFromTexture(Die->Icon.Get());
					Name->SetText(Die->Name);
					UE_LOG(LogTemp, Warning, TEXT("Loading Dice"));
				}
			}
		}
	});

	AssetManager.LoadPrimaryAsset(Die, { "UI" }, LoadCompleteDelegate);

	if (BtnAdd && BtnSub)
	{
		BtnAdd->OnClicked.AddDynamic(this, &UWDice_DieSelector::IncrementAmount);
		BtnSub->OnClicked.AddDynamic(this, &UWDice_DieSelector::DecrementAmount);
	}
}

void UWDice_DieSelector::UpdateCountText() const
{
	if (Count)
	{
		const FString PaddedNumber = UStringUtils::PadInteger(Amount, 2, "0");
		Count->SetText(FText::FromString(PaddedNumber));
	}
}
