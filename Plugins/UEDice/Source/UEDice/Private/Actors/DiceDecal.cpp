/** This project is distributed "as is," without warranty of any kind, express or implied,
* including but not limited to the warranties of merchantability, fitness for a particular purpose,
 * and non-infringement. In no event shall the authors or copyright holders be liable for any claim, damages,
 * or other liability, whether in an action of contract, tort, or otherwise, arising from, out of,
 * or in connection with the project or the use or other dealings in the project.
 */

#include "Actors/DiceDecal.h"
#include "Components/DecalComponent.h"
#include "Net/UnrealNetwork.h"

ADiceDecal::ADiceDecal()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot") );
	RootComponent = SceneRoot;

	Decal = CreateDefaultSubobject<UDecalComponent>(TEXT("Decal"));
	Decal->SetupAttachment(SceneRoot); 
	Decal->DecalSize = FVector(2.5f, 2.5f, 2.5f);

	const FRotator DecalRotation = FRotator(90.f, 0.0f, 0.f);
	Decal->SetRelativeRotation(DecalRotation);

	//Replication
	bReplicates = true;
	
	DecalColor = FLinearColor::White;

}

void ADiceDecal::OnRep_Decal()
{
	// This function is called on clients when DecalColor replicates.
	if (Decal)
	{
		// Create or update a dynamic material instance on the decal.
		if (UMaterialInstanceDynamic* DynMat = Decal->CreateDynamicMaterialInstance())
		{
			// Assume the decal material has a parameter named "DecalColor"
			DynMat->SetVectorParameterValue(FName("DecalColor"), DecalColor);
		}
	}
}
inline void ADiceDecal::SetDecalColor(const FLinearColor& NewColor)
{
	// This function should only be called on the server.
	if (HasAuthority())
	{
		DecalColor = NewColor;
		// Optionally update on the server immediately.
		OnRep_Decal();
	}
}

inline void ADiceDecal::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	// Replicate our color property. The Decal component itself was created in the constructor,
	// so we don't need to replicate the pointer.
	DOREPLIFETIME(ADiceDecal, DecalColor);

}
