// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameDS_UnitManager.generated.h"

/**
 * 
 */
UCLASS()
class UGameDS_UnitManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UGameDS_UnitManager();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION(BlueprintCallable)
	int32 SpawnCharacter();
};
