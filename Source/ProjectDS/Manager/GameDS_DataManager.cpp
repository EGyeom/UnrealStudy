// Fill out your copyright notice in the Description page of Project Settings.
#include "GameDS_DataManager.h"
#include "GameDS_CustomData.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/PlayerStart.h" // 올바른 경로로 변경
#include "ProjectDS/Unit/HeroSpawnPoint.h"

void UGameDS_DataManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	SpawnUnitData = LoadObject<UGameDS_SpawnUnitData>(nullptr, *SpawnUnitDataPath.GetAssetPathString());
}

void UGameDS_DataManager::Deinitialize()
{
	Super::Deinitialize();
}

const FGameDS_SpawnData* UGameDS_DataManager::GetSpawnData()
{
	if(SpawnUnitData == nullptr)
		return nullptr;

	FGameDS_SpawnData& Data = SpawnUnitData->SpawnDataList[0];
	return &Data;
}

const FTransform UGameDS_DataManager::GetSpawnPointTransform(int32 PointNum)
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHeroSpawnPoint::StaticClass(), FoundActors);

	if (FoundActors.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("No actors found in the world."));
	}
	else
	{
		for (AActor* Actor : FoundActors)
		{
			AHeroSpawnPoint* SpawnPoint = Cast<AHeroSpawnPoint>(Actor);
			if (SpawnPoint == nullptr)
				return FTransform::Identity;

			if (SpawnPoint->SpawnPoint == PointNum)
				return SpawnPoint->GetTransform();
		}
	}
	return FTransform::Identity;
}
