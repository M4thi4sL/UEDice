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
