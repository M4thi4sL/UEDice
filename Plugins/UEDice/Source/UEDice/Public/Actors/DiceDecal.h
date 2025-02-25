/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiceDecal.generated.h"

class UDecalComponent;

UCLASS()
class UEDICE_API ADiceDecal : public AActor
{
	GENERATED_BODY()

public:
	/** Sets default values for this actor's properties */
	ADiceDecal();

	/** Root component for organizing the hierarchy */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	
	/** Decal visualisation */
	UPROPERTY(ReplicatedUsing = OnRep_Decal, VisibleAnywhere, BlueprintReadOnly, Category = "Dice")
	UDecalComponent* Decal;
	
	/** Sets the decal color (should be called on the server) */
    void SetDecalColor(const FLinearColor& NewColor);

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UFUNCTION()
	void OnRep_Decal();
		
	/** Replicated color that determines the decal appearance */
	UPROPERTY(ReplicatedUsing = OnRep_Decal, BlueprintReadOnly, Category = "Dice")
	FLinearColor DecalColor;

};

