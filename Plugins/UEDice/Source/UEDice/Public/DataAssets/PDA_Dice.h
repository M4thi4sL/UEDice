/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */


#pragma once

#include "CoreMinimal.h"
#include "PDA_Base.h"
#include "Engine/DataAsset.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInterface.h"
#include "PDA_Dice.generated.h"

/** Enum for defining dice types */
UENUM(BlueprintType)
enum class EDiceType : uint8
{
    D2 UMETA(DisplayName = "D2"),
    D4 UMETA(DisplayName = "D4"),
    D6 UMETA(DisplayName = "D6"),
    D8 UMETA(DisplayName = "D8"),
    D10 UMETA(DisplayName = "D10"),
    D12 UMETA(DisplayName = "D12"),
    D20 UMETA(DisplayName = "D20"),
};

/**
 * c++ base class for dice, holds all information about the dies faces, visual representation, and other metadata.
 */
UCLASS(BlueprintType)
class UEDICE_API UPDA_Dice : public UPDA_Base
{
    GENERATED_BODY()

public:

    virtual FPrimaryAssetId GetPrimaryAssetId() const override;
    
    /**
     * A map associating face index with its label (e.g., 1, 2, 3, etc. or any custom string)
     * INT32 matches the socket name of the static mesh
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (EditCondition = "bHasValidMesh"))
    TMap<FString, FText> FaceLabels;

    /** Debug data, stores the normal of the faces of the die. This date gets then used when deciding if the die is in a valid position*/
    UPROPERTY(VisibleAnywhere , BlueprintReadOnly, Category = "DiceData")
    TArray<FVector> FaceNormals;
    
    /** The mesh to use for rendering the dice (soft pointer) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (AssetBundles="Game"))
    TSoftObjectPtr<UStaticMesh> DiceMesh;

    /** The material to apply to the dice mesh (soft pointer)  */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (AssetBundles="Game"))
    TSoftObjectPtr<UMaterialInterface> DiceMaterial;

    /** Enum representing the type of dice (D6, D20, etc.)  */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData")
    EDiceType DiceType;
    
    /** The class to use for this dice type (e.g., a subclass of AActor or UIndividualDice) (soft pointer) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (AssetBundles="Game"))
    TSoftClassPtr<UObject> DiceClass;

    #if WITH_EDITOR
        /** Called when a property is changed in the editor */
        virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
    #endif

private:
    #if WITH_EDITOR
        /** Internal function to automatically populate the map with its sockets when mesh is assigned */
        void AutoFillFaceDetails();

        /** Internal function that calculates the valid face normals */
        void AutoFillFaceNormals();
    
        /** Updates bHasValidMesh based on DiceMesh state */
        void UpdateValidMeshStatus();
    #endif
        
    #if WITH_EDITORONLY_DATA
        /** Boolean property for EditCondition to check if a valid mesh is provided */
        UPROPERTY(Transient)
        bool bHasValidMesh = false;
    #endif
    

};