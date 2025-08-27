#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameDS_Character.generated.h"

UCLASS()
class PROJECTDS_API AGameDS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameDS_Character();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
