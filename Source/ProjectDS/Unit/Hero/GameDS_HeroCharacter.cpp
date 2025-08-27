#include "GameDS_HeroCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AGameDS_HeroCharacter::AGameDS_HeroCharacter()
{
}

void AGameDS_HeroCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AGameDS_HeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameDS_HeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
