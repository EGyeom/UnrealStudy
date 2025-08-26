// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "HeroSpawnPoint.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDS_API AHeroSpawnPoint : public APlayerStart
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SpawnPoint;
};
