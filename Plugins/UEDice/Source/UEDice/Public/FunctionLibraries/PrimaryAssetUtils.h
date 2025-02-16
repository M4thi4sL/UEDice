/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PrimaryAssetUtils.generated.h"


// Sort order 
UENUM(BlueprintType)
enum class ESortOrder : uint8
{
	Ascending,
	Descending
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnAssetLoaded, UObject*, LoadedAsset);

/**
 * c++ function library that deals with primary assets.
 */
UCLASS()
class UEDICE_API UPrimaryAssetUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	/**
	 * Asynchronously loads a primary asset and calls the provided callback when done.
	 *
	 * @param PrimaryAssetId - The ID of the primary asset to load.
	 * @param OnCompleted - Delegate that is executed when the asset is loaded.
	 * @param Bundles  - What bundles to load?
	 */
	UFUNCTION(BlueprintCallable, Category = "AssetManager", meta = (DisplayName = "Async Load Primary Asset (NonLatent)"))
	static void LoadPrimaryAssetAsync(FPrimaryAssetId PrimaryAssetId, const TArray<FName>& Bundles, const FOnAssetLoaded& OnCompleted);
	
	/**
	 * Retrieves and sorts primary asset IDs of the specified type.
	 *
	 * Queries primary assets by type, sorts them by their `UIOrderIndex` metadata in ascending or descending order, 
	 * and returns a sorted array of `FPrimaryAssetId` without loading the assets.
	 *
	 * @param PrimaryAssetType The type of primary asset to retrieve.
	 * @param Order Specifies the sorting order (ascending or descending).
	 * @return A sorted array of `FPrimaryAssetId`, or an empty array if none are found.
	 */
	UFUNCTION(BlueprintCallable, Category = "AssetManager", meta = (DisplayName = "Get Sorted Primary Assets Id List",  AutoCreateRefTerm = "AssetType"))
	static TArray<FPrimaryAssetId> GetSortedPrimaryAssetIds(const FPrimaryAssetType PrimaryAssetType, const ESortOrder Order);

private:
	
	static int32 GetOrderIndexFromPath(const FSoftObjectPath& AssetPath);
	
	
};
