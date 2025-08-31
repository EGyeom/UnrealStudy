// Fill out your copyright notice in the Description page of Project Settings.
#include "GameDS_DataManager.h"
#include "GameDS_CustomData.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/PlayerStart.h" // 올바른 경로로 변경
#include "ProjectDS/Unit/Spawner/HeroSpawnPoint.h"

void UGameDS_DataManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	SpawnUnitData = LoadObject<UGameDS_SpawnUnitData>(nullptr, *SpawnUnitDataPath.GetAssetPathString());
	HeroStatConfigData = LoadObject<UGameDS_HeroStatConfigData>(nullptr, *HeroStatConfigDataPath.GetAssetPathString());
	DefaultHeroSetting = LoadObject<UGameDS_DefaultHeroSetting>(nullptr, *DefaultHeroSettingDataPath.GetAssetPathString());

	EnemyStatConfigData = LoadObject<UDataTable>(nullptr, *EnemyStatConfigDataPath.GetAssetPathString());
	HeroSkillData = LoadObject<UDataTable>(nullptr, *HeroSkillDataPath.GetAssetPathString());
	EnemySkillData = LoadObject<UDataTable>(nullptr, *EnemySkillDataPath.GetAssetPathString());
	HeroSkillInfoData = LoadObject<UDataTable>(nullptr, *HeroSkillInfoDataPath.GetAssetPathString());
	EnemySkillInfoData = LoadObject<UDataTable>(nullptr, *EnemySkillInfoDataPath.GetAssetPathString());
	
	CollisionInfoData = LoadObject<UDataTable>(nullptr, *CollisionInfoDataPath.GetAssetPathString());
	EnemySkillSettingData = LoadObject<UDataTable>(nullptr, *EnemySkillSettingDataPath.GetAssetPathString());
	SkillSetData = LoadObject<UDataTable>(nullptr, *SkillSetPath.GetAssetPathString());
	HeroSkillSetData = LoadObject<UDataTable>(nullptr, *HeroSkillSetPath.GetAssetPathString());

	CrowdControlInfoData = LoadObject<UDataTable>(nullptr , *CrowdControlInfoDataPath.GetAssetPathString());
	StatusEffectInfoData = LoadObject<UDataTable>(nullptr, *StatusEffectInfoDataPath.GetAssetPathString());

	SummonData = LoadObject<UDataTable>(nullptr, *SummonDataPath.GetAssetPathString());
	WeaponData = LoadObject<UDataTable>(nullptr, *WeaponDataPath.GetAssetPathString());
	PotionData = LoadObject<UDataTable>(nullptr, *PotionDataPath.GetAssetPathString());

	InitSkillData();
	InitSkillInfoData();
	InitItemData();

	
	AddDataTable<FGameDS_EnemyStatConfigDataTable>(EnemyStatConfigData);
	AddDataTable<FGameDS_SkillDataTable>(SkillData);
	AddDataTable<FGameDS_SkillInfoDataTable>(SkillInfoData);
	AddDataTable<FGameDS_CollisionInfoDataTable>(CollisionInfoData);
	AddDataTable<FGameDS_EnemySkillSettingDataTable>(EnemySkillSettingData);
	AddDataTable<FGameDS_ItemDataTable>(ItemData);
	AddDataTable<FGameDS_SkillSetDataTable>(SkillSetData);
	AddDataTable<FGameDS_HeroSkillSetDataTable>(HeroSkillSetData);
	AddDataTable<FGameDS_SummonDataTable>(SummonData);
	AddDataTable<FGameDS_WeaponDataTable>(WeaponData);
	AddDataTable<FGameDS_PotionDataTable>(PotionData);
	AddDataTable<FGameDS_CrowdControlInfoDataTable>(CrowdControlInfoData);
	AddDataTable<FGameDS_StatusEffectInfoDataTable>(StatusEffectInfoData);
}

void UGameDS_DataManager::Deinitialize()
{
	Super::Deinitialize();
}

const FGameDS_SpawnData* UGameDS_DataManager::GetSpawnData(const FGameDS_UnitSpawnOption& SpawnOption) const
{
	if(SpawnOption.UnitType == EGameDS_UnitType::None)
		return nullptr;
	if(SpawnUnitData == nullptr)
		return nullptr;

	for (const FGameDS_SpawnData& Data : SpawnUnitData->SpawnDataList)
	{
		if(Data.UnitType != SpawnOption.UnitType)
			continue;

		if(Data.DataID != SpawnOption.DataID)
			continue;
		
		if(Data.CharacterBP.Get() == nullptr)
			break;
		
		return &Data;
	}

	return nullptr;
}

const UGameDS_HeroStatConfigData* UGameDS_DataManager::GetHeroStatConfigData() const
{
	return HeroStatConfigData;
}

void UGameDS_DataManager::GetHeroStatConfigData(FGameDS_UnitStatInfo& UnitStatInfo, FGameDS_HeroStatInfo& HeroStatInfo) const
{
	if (HeroStatConfigData)
	{
		UnitStatInfo = HeroStatConfigData->GetUnitStatInfo();
		HeroStatInfo = HeroStatConfigData->GetHeroStatInfo();
	}
}