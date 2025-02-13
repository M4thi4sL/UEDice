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
	// Sets default values for this actor's properties
	ADiceDecal();

	// Root component for organizing the hierarchy
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SceneRoot;
	
	// Decal visualisation
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Dice")
	UDecalComponent* Decal;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
