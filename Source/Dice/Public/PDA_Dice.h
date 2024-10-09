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
    D4 UMETA(DisplayName = "D4"),
    D6 UMETA(DisplayName = "D6"),
    D8 UMETA(DisplayName = "D8"),
    D10 UMETA(DisplayName = "D10"),
    D12 UMETA(DisplayName = "D12"),
    D20 UMETA(DisplayName = "D20"),
};

/**
 * A data asset to hold information about the dice's faces, visual representation, and metadata.
 */
UCLASS(BlueprintType)
class DICE_API UPDA_Dice : public UPDA_Base
{
    GENERATED_BODY()

public:

    virtual FPrimaryAssetId GetPrimaryAssetId() const override;
    
    /** A map associating face index with its label (e.g., 1, 2, 3, etc. or any custom string)
     INT32 matches the socket name of the static mesh */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (EditCondition = "bHasValidMesh"))
    TMap<FString, FText> FaceLabels;

    UPROPERTY(VisibleAnywhere , BlueprintReadOnly, Category = "DiceData")
    TArray<FVector> FaceNormals;
    
    // The mesh to use for rendering the dice (soft pointer)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (AssetBundles="Game"))
    TSoftObjectPtr<UStaticMesh> DiceMesh;

    // The material to apply to the dice mesh (soft pointer)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (AssetBundles="Game"))
    TSoftObjectPtr<UMaterialInterface> DiceMaterial;

    // Enum representing the type of dice (D6, D20, etc.)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData")
    EDiceType DiceType;
    
    // The class to use for this dice type (e.g., a subclass of AActor or UIndividualDice) (soft pointer)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DiceData", meta = (AssetBundles="Game"))
    TSoftClassPtr<UObject> DiceClass;

    #if WITH_EDITOR
        // Called when a property is changed in the editor
        virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
    #endif

private:
    #if WITH_EDITOR
        // Internal function to automatically populate the map with its sockets when mesh is assigned
        void AutoFillFaceDetails();

        // Internal function that calculates the valid face normals
        void AutoFillFaceNormals();
    
        // Updates bHasValidMesh based on DiceMesh state
        void UpdateValidMeshStatus();
    #endif
        
    #if WITH_EDITORONLY_DATA
        // Boolean property for EditCondition to check if a valid mesh is provided
        UPROPERTY(Transient)
        bool bHasValidMesh = false;
    #endif
    

};