// Fill out your copyright notice in the Description page of Project Settings.
#include "GameDS_DataManager.h"
#include "GameDS_CustomData.h"
#include "GameFramework/Character.h"
#include <Kismet/GameplayStatics.h>
#include "GameFramework/PlayerStart.h" // 올바른 경로로 변경
#include "ProjectDS/Unit/Spawner/HeroSpawnPoint.h"

void UGameDS_DataManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	LoadAllDataTables();
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
		UnitStatInfo = HeroStatConfigData->UnitStatInfo;
		HeroStatInfo = HeroStatConfigData->HeroStatInfo;
	}
}

void UGameDS_DataManager::GetHeroCreateData(FGameDS_HeroCreateInfo& CreateInfo)
{
	CreateInfo = HeroCreateInfo;
}


void UGameDS_DataManager::GetEnemyStatConfigData(int32 InDataID, FGameDS_UnitStatInfo& UnitStatInfo)
{

	if (const FGameDS_EnemyStatConfigDataTable* StatConfigData = GetDataInRow<FGameDS_EnemyStatConfigDataTable>(InDataID))
	{
		UnitStatInfo = StatConfigData->UnitStatInfo;
	}

}

const FGameDS_SkillDataTable* UGameDS_DataManager::GetSkillData(int32 InSkillID) const
{
	return nullptr;
}

const FGameDS_SkillInfoDataTable* UGameDS_DataManager::GetSkillInfoData(int32 InSkillID) const
{
	return nullptr;
}

const FGameDS_CollisionInfoDataTable* UGameDS_DataManager::GetCollisionInfoData(int32 InCollisionID) const
{
	return nullptr;
}

FGameDS_WeaponDataTable* UGameDS_DataManager::GetWeaponData(int32 InWeaponID) const
{
	return nullptr;
}

void UGameDS_DataManager::InitLastSerialID(int32 InLastSerialID)
{
}

int32 UGameDS_DataManager::CreateItemSerialID()
{
	return int32();
}

void UGameDS_DataManager::LoadHeroData(FGameDS_HeroCreateInfo& CreateInfo)
{
}

void UGameDS_DataManager::SaveHeroData(FGameDS_HeroCreateInfo& InHeroCreateInfo, bool bDefaultSetting)
{
}

void UGameDS_DataManager::SaveDataWithBool(FString Section, FString Key, const bool Value)
{
}

void UGameDS_DataManager::SaveDataWithInt(FString Section, FString Key, const int32 Value)
{
}

void UGameDS_DataManager::SaveData(FString Section, FString Key, const TArray<FString>& Value)
{
}

bool UGameDS_DataManager::LoadData(FString Section, FString Key, TArray<FString>& Value)
{
	return false;
}

bool UGameDS_DataManager::LoadDataWithBool(FString Section, FString Key, bool& Value)
{
	return false;
}

bool UGameDS_DataManager::LoadDataWithInt(FString Section, FString Key, int32& Value)
{
	return false;
}

void UGameDS_DataManager::SaveFirstData(FGameDS_HeroCreateInfo InHeroCreateInfo)
{
}

FTransform UGameDS_DataManager::GetSpawnPointTransform()
{
	return FTransform();
}

bool UGameDS_DataManager::IsValidSpawnPoint(int32 InSpawnPoint)
{
	return false;
}

bool UGameDS_DataManager::IsValidGameData() const
{
	return false;
}

void UGameDS_DataManager::LoadAllDataTables()
{
	SpawnUnitData = LoadObject<UGameDS_SpawnUnitData>(nullptr, *SpawnUnitDataPath.GetAssetPathString());
	HeroStatConfigData = LoadObject<UGameDS_HeroStatConfigData>(nullptr, *HeroStatConfigDataPath.GetAssetPathString());
	DefaultHeroSetting = LoadObject<UGameDS_DefaultHeroSetting>(nullptr, *DefaultHeroSettingDataPath.GetAssetPathString());

	AddDataTable<FGameDS_EnemyStatConfigDataTable>(LoadObject<UDataTable>(nullptr, *EnemyStatConfigDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_CollisionInfoDataTable>(LoadObject<UDataTable>(nullptr, *CollisionInfoDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_EnemySkillSettingDataTable>(LoadObject<UDataTable>(nullptr, *EnemySkillSettingDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_SkillSetDataTable>(LoadObject<UDataTable>(nullptr, *SkillSetPath.GetAssetPathString()));
	AddDataTable<FGameDS_HeroSkillSetDataTable>(LoadObject<UDataTable>(nullptr, *HeroSkillSetPath.GetAssetPathString()));
	AddDataTable<FGameDS_SummonDataTable>(LoadObject<UDataTable>(nullptr, *SummonDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_WeaponDataTable>(LoadObject<UDataTable>(nullptr, *WeaponDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_PotionDataTable>(LoadObject<UDataTable>(nullptr, *PotionDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_CrowdControlInfoDataTable>(LoadObject<UDataTable>(nullptr, *CrowdControlInfoDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_StatusEffectInfoDataTable>(LoadObject<UDataTable>(nullptr, *StatusEffectInfoDataPath.GetAssetPathString()));
	AddDataTable<FGameDS_SkillDataTable>(LoadObject<UDataTable>(nullptr, *HeroSkillDataPath.GetAssetPathString()));
	//AddDataTable<FGameDS_SkillDataTable>(LoadObject<UDataTable>(nullptr, *EnemySkillDataPath.GetAssetPathString()));

	InitSkillData();
	InitSkillInfoData();
	InitItemData();
}

void UGameDS_DataManager::InitSkillData()
{
	UDataTable* CombinedTable = NewObject<UDataTable>();
	CombinedTable->RowStruct = FGameDS_SkillDataTable::StaticStruct();
	
	//if(GetDataTable<FGameDS_SkillDataTable>)
	{
		//AddDataTable<FGameDS_SkillDataTable>(HeroSkillData);
	}

	//if(EnemySkillData != nullptr)
	{
		//AddDataTable<FGameDS_SkillDataTable>(EnemySkillData);
	}
}

void UGameDS_DataManager::InitSkillInfoData()
{
	UDataTable* Hero = LoadObject<UDataTable>(nullptr, *HeroSkillInfoDataPath.GetAssetPathString());
	UDataTable* Enemy = LoadObject<UDataTable>(nullptr, *EnemySkillInfoDataPath.GetAssetPathString());

	if(Hero != nullptr)
	{
		AddDataTable<FGameDS_SkillInfoDataTable>(Hero);
	}

	if(Enemy != nullptr)
	{
		AddDataTable<FGameDS_SkillInfoDataTable>(Enemy);
	}
}

void UGameDS_DataManager::InitItemData()
{
	const UDataTable* WeaponData = GetDataTable<FGameDS_WeaponDataTable>();
	const UDataTable* PotionData = GetDataTable<FGameDS_PotionDataTable>();
}
