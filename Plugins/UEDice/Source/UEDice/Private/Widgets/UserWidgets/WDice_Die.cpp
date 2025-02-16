// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Widgets/UserWidgets/WDice_Die.h"

#include "Actors/DiceActor.h"
#include "Components/Border.h"
#include "Engine/StreamableManager.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "DataAssets/PDA_Dice.h"
#include "Engine/AssetManager.h"
#include "FunctionLibraries/StringUtils.h"


class UPDA_Dice;

void UWDice_Die::UpdateDieStatus(const FText& NewDieStatus)
{
	if (Status) Status->SetText(NewDieStatus);
}

void UWDice_Die::UpdateDieState(const EDieState& NewDieState)
{
	if (Status) Status->SetText(UStringUtils::GetEnumAsText(NewDieState));

	if (Result && Status && Score)
	{
		FSlateColor ColorToUse;

		switch ( NewDieState)
		{
		case EDieState::Idle:
			ColorToUse = FColor::White;
			break;
		case EDieState::Stopped:
			ColorToUse = FColor::White;
			Invalid->SetVisibility(ESlateVisibility::Hidden);
			break;
		case EDieState::Invalid:
			ColorToUse = FColor::Red;
			Invalid->SetVisibility(ESlateVisibility::HitTestInvisible);
			break;
		case EDieState::Rolling:
			ColorToUse = FColor::FromHex("C3C3C3FF");
			Invalid->SetVisibility(ESlateVisibility::Hidden);
			UpdateDieResult(FText::FromString("-"));
			break;
			
		}
		
		Result->SetColorAndOpacity(ColorToUse);
		Status->SetColorAndOpacity(ColorToUse);
		Score->SetColorAndOpacity(ColorToUse);
	}
}

void UWDice_Die::UpdateDieResult(const FText& NewResult)
{
	if (Result) Result->SetText(NewResult);
}

void UWDice_Die::InitializeWidget_Implementation()
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
				if (Icon && Name)
				{
					Icon->SetBrushFromTexture(Die->Icon.Get());
					Icon->SetToolTipText(Die->Description);
					Name->SetText(Die->Name);
				}
			}
		}
	});

	AssetManager.LoadPrimaryAsset(Die, { "UI" }, LoadCompleteDelegate);}

void UWDice_Die::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

	SetHover(true);

	if (OnDieWidgetHovered.IsBound()) OnDieWidgetHovered.Broadcast(this);
}

void UWDice_Die::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);

	SetHover(false);

	if (OnDieWidgetHoveredEnd.IsBound())OnDieWidgetHoveredEnd.Broadcast(this);
}

FReply UWDice_Die::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		if (OnDieWidgetClicked.IsBound()) OnDieWidgetClicked.Broadcast(this);
		return FReply::Handled();
	}

	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UWDice_Die::SetHover(const bool bIsHovered) const 
{
	if (Border)
	{
		const FLinearColor HoverColor = FLinearColor(1.0f, 1.0f, 1.0f, bIsHovered ? 0.5f : 0.05f);
		Border->SetBrushColor(HoverColor);
	}
}

void UWDice_Die::SetDieId(const FPrimaryAssetId NewDieId)
{
	Die = NewDieId;
}
