/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#include "FunctionLibraries/PrimaryAssetUtils.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"

void UPrimaryAssetUtils::LoadPrimaryAssetAsync(FPrimaryAssetId PrimaryAssetId, const TArray<FName>& Bundles,
                                               const FOnAssetLoaded& OnCompleted)
{
	if (!PrimaryAssetId.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid PrimaryAssetId passed to LoadPrimaryAssetAsync."));
		return;
	}

	UAssetManager* AssetManager = UAssetManager::GetIfInitialized();
	if (!AssetManager)
	{
		UE_LOG(LogTemp, Error, TEXT("AssetManager not valid!"));
		return;
	}

	const FStreamableDelegate LoadCompleteDelegate = FStreamableDelegate::CreateLambda([PrimaryAssetId, OnCompleted]()
	{
		if (const UAssetManager* InnerAssetManager = UAssetManager::GetIfInitialized())
		{
			UObject* LoadedAsset = InnerAssetManager->GetPrimaryAssetObject(PrimaryAssetId);
			if (OnCompleted.IsBound())
			{
				OnCompleted.Execute(LoadedAsset);
			}
		}
	});

	AssetManager->LoadPrimaryAsset(PrimaryAssetId, Bundles, LoadCompleteDelegate);
}

TArray<FPrimaryAssetId> UPrimaryAssetUtils::GetSortedPrimaryAssetIds(const FPrimaryAssetType PrimaryAssetType,
	const ESortOrder Order)
{
		TArray<FPrimaryAssetId> SortedAssetIds;

		UAssetManager* AssetManager = UAssetManager::GetIfInitialized();
		if (!AssetManager)
		{
			UE_LOG(LogTemp, Error, TEXT("Asset Manager not found."));
			return SortedAssetIds;
		}

		/** Retrieve asset IDs of the specified type */
		AssetManager->GetPrimaryAssetIdList(PrimaryAssetType, SortedAssetIds);

		/** Sort the primary asset IDs by their UIOrderIndex from metadata */
		SortedAssetIds.Sort([&](const FPrimaryAssetId& A, const FPrimaryAssetId& B)
			{
				/** Retrieve the paths for the primary asset IDs */
				const FSoftObjectPath PathA = AssetManager->GetPrimaryAssetPath(A);
				const FSoftObjectPath PathB = AssetManager->GetPrimaryAssetPath(B);

				/** Query UIOrderIndex for each asset */
				const int32 IndexA = GetOrderIndexFromPath(PathA); 
				const int32 IndexB = GetOrderIndexFromPath(PathB);

				/** Determine sorting logic based on the order */
				return (Order == ESortOrder::Ascending) ? (IndexA < IndexB) : (IndexA > IndexB);
			});

		return SortedAssetIds;
}

int32 UPrimaryAssetUtils::GetOrderIndexFromPath(const FSoftObjectPath& AssetPath)
{
	if (!AssetPath.IsValid())
	{
		return MAX_int32;
	}

	/** Access the Asset Registry */
	IAssetRegistry& AssetRegistry = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry").Get();

	/** Retrieve the AssetData for the given path */
	const FAssetData AssetData = AssetRegistry.GetAssetByObjectPath(AssetPath);
	if (AssetData.IsValid())
	{
		/** Query the "UIOrderIndex" property directly */
		int32 OrderIndex = 0;
		if (AssetData.GetTagValue(FName("UIOrderIndex"), OrderIndex))
		{
			return OrderIndex;
		}
	}

	return MAX_int32;

}
