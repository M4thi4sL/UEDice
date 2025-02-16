// This project is distributed "as is," without warranty of any kind, express or implied, including but not limited to the warranties of merchantability, fitness for a particular purpose, and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages, or other liability, whether in an action of contract, tort, or otherwise, arising from, out of, or in connection with the project or the use or other dealings in the project.


#include "Widgets/UserWidgets/WDice_Controls.h"

#include "Actors/DiceThrower.h"
#include "Actors/DiceActor.h"
#include "Components/PanelWidget.h"
#include "FunctionLibraries/PrimaryAssetUtils.h"

#include "Kismet/GameplayStatics.h"
#include "Widgets/UserWidgets/WDice_Button.h"
#include "Widgets/UserWidgets/WDice_Die.h"
#include "Widgets/UserWidgets/WDice_DieSelector.h"
#include "Widgets/UserWidgets/WDice_Tally.h"

void UWDice_Controls::NativeConstruct()
{
	Super::NativeConstruct();

	DiceThrower = Cast<ADiceThrower>(UGameplayStatics::GetActorOfClass(GetWorld(), DiceThrower->StaticClass()));

	if(DiceThrower)
	{
		DiceThrower->OnDieSpawned.AddDynamic(this,&UWDice_Controls::OnDieSpawned);
		DiceThrower->OnDiceCleared.AddDynamic(this,&UWDice_Controls::OnDiceCleared);
		DiceThrower->OnResultChanged.AddDynamic(this, &UWDice_Controls::OnTotalResultChanged);
	}

	if (BtnClearDice && BtnResetDice && BtnRollDice && BtnSpawnDice)
	{
		BtnClearDice->OnButtonClicked.AddDynamic(this, &UWDice_Controls::HandleClearDicePressed);
		BtnResetDice->OnButtonClicked.AddDynamic(this, &UWDice_Controls::HandleResetDicePressed);
		BtnRollDice->OnButtonClicked.AddDynamic(this, &UWDice_Controls::HandleRollDicePressed);
		BtnSpawnDice->OnButtonClicked.AddDynamic(this, &UWDice_Controls::HandleSpawnDicePressed);
	}
}

void UWDice_Controls::InitializeWidget_Implementation()
{
	Super::InitializeWidget_Implementation();

	if (DieButtonsBox) DieButtonsBox->ClearChildren();

	TArray<FPrimaryAssetId> DiceIds = UPrimaryAssetUtils::GetSortedPrimaryAssetIds(FPrimaryAssetType("Dice"), ESortOrder::Ascending);

	for (const FPrimaryAssetId Id : DiceIds)
	{
		if (!WDieSelector) return;
		if (UWDice_DieSelector* DieSelectorWidget = Cast<UWDice_DieSelector>(CreateWidget(this, WDieSelector)))
		{
			DieSelectorWidget->SetDieId(Id);
			
			DieButtonsBox->AddChild(DieSelectorWidget);
			DiceSelectors.Add(DieSelectorWidget);
			
			DieSelectorWidget->OnAddDice.AddDynamic(this, &UWDice_Controls::OnDieAdded);
			DieSelectorWidget->OnRemoveDice.AddDynamic(this, &UWDice_Controls::OnDieRemoved);
		}
	}
}

void UWDice_Controls::OnDieSpawned(ADiceActor* SpawnedDie)
{
	/** 1. bind to the delegates of the DiceActor */
	if (SpawnedDie)
	{
		SpawnedDie->OnDieStateChanged.AddDynamic(this, &UWDice_Controls::OnDieStateChanged);
		SpawnedDie->OnDieResult.AddDynamic(this, &UWDice_Controls::OnDieResult);
		SpawnedDie->OnDieHover.AddDynamic(this, &UWDice_Controls::OnDieHover);
		SpawnedDie->OnDieHoverEnd.AddDynamic(this, &UWDice_Controls::OnDieHoverEnd);
	}

	/** 2. Create the widget representing the DiceActor */
	if (!WDie) return;
	if (UWDice_Die* DiceWidget = Cast<UWDice_Die>(CreateWidget(this, WDie)))
	{
		DiceWidget->SetDieId(SpawnedDie->DiceId);
		DiceWidget->SetPadding(FMargin(0.0f, 2.0f, 0.0f, 2.0f));
		if (DiceBox) DiceBox->AddChild(DiceWidget);
		DiceMap.Add(SpawnedDie, DiceWidget);

		DiceWidget->OnDieWidgetHovered.AddDynamic(this, &UWDice_Controls::OnDieWidgetHover);
		DiceWidget->OnDieWidgetHoveredEnd.AddDynamic(this, &UWDice_Controls::OnDieWidgetHoverEnd);
		DiceWidget->OnDieWidgetClicked.AddDynamic(this, &UWDice_Controls::OnDieWidgetClicked);
	}
	
	/** 3. update the tally */
	if (Tally)
	{
		Tally->SetDiceNumber(FText::FromString(FString::FromInt(DiceMap.Num())));
		Tally->SetScoreTotal(FText::FromString(FString::FromInt(DiceMap.Num())));
	}
}

void UWDice_Controls::OnDiceCleared()
{
	DiceMap.Empty();

	if (DiceBox && Tally)
	{
		DiceBox->ClearChildren();
		Tally->Clear();		
	}
}

void UWDice_Controls::OnTotalResultChanged(const FText& NewText)
{
	if (Tally) Tally->SetScoreTotal(NewText);
}

void UWDice_Controls::OnDieStateChanged(ADiceActor* Die, const EDieState& NewDieState)
{
	UWDice_Die** DieWidget = DiceMap.Find(Die);
	(*DieWidget)->UpdateDieState(NewDieState);
}

void UWDice_Controls::OnDieResult(ADiceActor* Die, const FText& NewResult)
{
	UWDice_Die** DieWidget = DiceMap.Find(Die);
	(*DieWidget)->UpdateDieResult(NewResult);
}

void UWDice_Controls::OnDieHover(ADiceActor* Die)
{
	UWDice_Die** DieWidget = DiceMap.Find(Die);
	(*DieWidget)->SetHover(true);
}

void UWDice_Controls::OnDieHoverEnd(ADiceActor* Die)
{
	UWDice_Die** DieWidget = DiceMap.Find(Die);
	(*DieWidget)->SetHover(false);
}

void UWDice_Controls::OnDieAdded(FPrimaryAssetId Die)
{
	DiceThrower->AddDice(Die);
}

void UWDice_Controls::OnDieRemoved(FPrimaryAssetId Die)
{
	DiceThrower->RemoveDice(Die);
}

void UWDice_Controls::OnDieWidgetHover(UWDice_Die* DieWidget)
{
	TArray<ADiceActor*> DiceActors;
	TArray<UWDice_Die*> DiceWidgets;
	DiceMap.GenerateValueArray(DiceWidgets);
	DiceMap.GenerateKeyArray(DiceActors);

	DiceActors[DiceWidgets.Find(DieWidget)]->HandleBeginCursorOver(nullptr);
}

void UWDice_Controls::OnDieWidgetHoverEnd(UWDice_Die* DieWidget)
{
	TArray<ADiceActor*> DiceActors;
    TArray<UWDice_Die*> DiceWidgets;
    DiceMap.GenerateValueArray(DiceWidgets);
    DiceMap.GenerateKeyArray(DiceActors);

    DiceActors[DiceWidgets.Find(DieWidget)]->HandleEndCursorOver(nullptr);
}

void UWDice_Controls::OnDieWidgetClicked(UWDice_Die* DieWidget)
{
	TArray<ADiceActor*> DiceActors;
    TArray<UWDice_Die*> DiceWidgets;
    DiceMap.GenerateValueArray(DiceWidgets);
    DiceMap.GenerateKeyArray(DiceActors);

    ADiceActor* LocalDiceActor = DiceActors[DiceWidgets.Find(DieWidget)];
	if (DiceThrower) DiceThrower->RerollDice(LocalDiceActor);
}

void UWDice_Controls::HandleSpawnDicePressed(UWDiceUserWidget* Widget)
{
	if (DiceThrower) DiceThrower->SpawnDice();
}

void UWDice_Controls::HandleClearDicePressed(UWDiceUserWidget* Widget) 
{
	if (DiceThrower) DiceThrower->ClearDice();
}

void UWDice_Controls::HandleResetDicePressed(UWDiceUserWidget* Widget)
{
	for (UWDice_DieSelector* DieSelectorWidget : DiceSelectors)
	{
		DieSelectorWidget->ResetAmount();
	}
}

void UWDice_Controls::HandleRollDicePressed(UWDiceUserWidget* Widget) 
{
	if (DiceThrower) DiceThrower->RerollAll();
}
