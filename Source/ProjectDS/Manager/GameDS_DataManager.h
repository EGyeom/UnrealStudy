// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameDS_DataManager.generated.h"


class UGameDS_SpawnUnitData;
struct FGameDS_SpawnData;
/**
 * 
 */
UCLASS(Config = Game)
class PROJECTDS_API UGameDS_DataManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	const FGameDS_SpawnData* GetSpawnData();
	const FTransform GetSpawnPointTransform(int32 PointNum);
private:

	UPROPERTY(Config)
	FSoftClassPath SpawnUnitDataPath;
	UPROPERTY()
	UGameDS_SpawnUnitData* SpawnUnitData;
};
