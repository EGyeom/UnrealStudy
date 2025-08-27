#pragma once

#include "ProjectDS/Unit/GameDS_Character.h"
#include "GameDS_HeroCharacter.generated.h"

UCLASS()
class PROJECTDS_API AGameDS_HeroCharacter : public AGameDS_Character
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameDS_HeroCharacter();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
