/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#include "Actors/DiceDecal.h"
#include "Components/DecalComponent.h"

// Sets default values
ADiceDecal::ADiceDecal()
{
	PrimaryActorTick.bCanEverTick = false;

	// Create the scene root component (used as a dummy root)
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	// Create the decal component and attach it to the scene root
	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	Decal->SetupAttachment(SceneRoot); 
	Decal->DecalSize = FVector(2.5f, 2.5f, 2.5f);
	// Rotate the decal 90 degrees on the X-axis
	FRotator DecalRotation = FRotator(90.f, 0.0f, 0.f);
	Decal->SetRelativeRotation(DecalRotation);
}

// Called when the game starts or when spawned
void ADiceDecal::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADiceDecal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}