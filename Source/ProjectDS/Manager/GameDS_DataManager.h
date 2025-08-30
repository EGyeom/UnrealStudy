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

	template <typename DataStruct>
	const UDataTable* GetDataTable() const;
	template <typename DataStruct>
	const DataStruct GetDataInRow(int32 DataID);

	//Data Getter
	const FGameDS_SpawnData* GetSpawnData(); const;
	const UGameDS_HeroStatConfigData* GetHeroStatConfigData(); const;
	void GetHeroStatConfigData(FGameDS_UnitStatInfo& UnitStatInfo, FGameDS_HeroStatInfo& HeroStatInfo);
	void GetHeroCreateData(FGameDS_HeroCreateInfo& HeroCreateInfo);
	void GetEnemyStatConfigData(int32 InDataID, FGameDS_UnitStatInfo& UnitStatInfo);
	const FGameDS_SkillDataTable* GetSkillData(int32 InSkillID) const;
	const FGameDS_SkillInfoDataTable* GetSkillInfoData(int32 InSkillID) const;
	const FGameDS_CollisionInfoDataTable* GetCollisionInfoData(int32 InCollisionID) const;
	FGameDS_WeaponDataTable* GetWeaponData(int32 InWeaponID) const;

	void InitLastSerialID(int32 InLastSerialID);
	int32 CreateItemSerialID();

	UFUNCTION(BlueprintCallable)
	void LoadHeroData(FGameDS_HeroCreateInfo& CreateInfo);

	UFUNCTION(BlueprintCallable)
	void SaveHeroData(FGameDS_HeroCreateInfo& InHeroCreateInfo, bool bDefaultSetting = false);
	
	UFUNCTION(BlueprintCallable)
	void SaveDataWithBool(FString Section, FString Key, const bool Value);
	UFUNCTION(BlueprintCallable)
	void SaveDataWithInt(FString Section, FString Key, const int32 Value);
	UFUNCTION(BlueprintCallable)
	void SaveData(FString Section, FString Key, const TArray<FString>& Value);
	
	UFUNCTION(BlueprintCallable)
	bool LoadData(FString Section, FString Key, TArray<FString>& Value);
	UFUNCTION(BlueprintCallable)
	bool LoadDataWithBool(FString Section, FString Key, bool& Value);
	UFUNCTION(BlueprintCallable)
	bool LoadDataWithInt(FString Section, FString Key, int32& Value);

	UFUNCTION(BlueprintCallable)
	void SaveFirstData(FGameDS_HeroCreateInfo InHeroCreateInfo);

	UFUNCTION(BlueprintCallable)
	FTransform GetSpawnPointTransform();

	UFUNCTION(BlueprintCallable)
	bool IsValidSpawnPoint(int32 InSpawnPoint);

	UFUNCTION(BlueprintCallable)
	bool IsValidGameData() const;

private:
	template <typename DataStruct>
	void AddDataTable(UDataTable* DataTable);

	void InitSkillData();
	void InitSkillInfoData();

	void InitItemData();

	// DataAsset
	UPROPERTY(Config)
	FSoftClassPath SpawnUnitDataPath;
	UPROPERTY()
	UGameDS_SpawnUnitData* SpawnUnitData;

	UPROPERTY(Config)
	FSoftClassPath HeroStatConfigDataPath;
	UPROPERTY()
	UGameDS_HeroStatConfigData* HeroStatConfigData;

	UPROPERTY(Config)
	FSoftClassPath DefaultHeroSettingDataPath;
	UPROPERTY()
	UGameDS_DefaultHeroSetting* DefaultHeroSetting;

	// DataTable
	UPROPERTY(Config)
	FSoftClassPath EnemyStatConfigDataPath;
	UPROPERTY()
	UDataTable* EnemyStatConfigData;
	
	UPROPERTY(Config)
	FSoftClassPath HeroSkillDataPath;
	UPROPERTY()
	UDataTable* HeroSkillData;
	
	UPROPERTY(Config)
	FSoftClassPath EnemySkillDataPath;
	UPROPERTY()
	UDataTable* EnemySkillData;

	UPROPERTY(Config)
	FSoftClassPath HeroSkillInfoDataPath;
	UPROPERTY()
	UDataTable* HeroSkillInfoData;

	UPROPERTY(Config)
	FSoftClassPath EnemySkillInfoDataPath;
	UPROPERTY()
	UDataTable* EnemySkillInfoData;

	// common
	UPROPERTY()
	UDataTable* SkillData;
	
	UPROPERTY()
	UDataTable* SkillInfoData;
	//

	UPROPERTY(Config)
	FSoftClassPath CollisionInfoDataPath;
	UPROPERTY()
	UDataTable* CollisionInfoData;
	
	UPROPERTY(Config)
	FSoftClassPath EnemySkillSettingDataPath;
	UPROPERTY()
	UDataTable* EnemySkillSettingData;

	// common
	UPROPERTY()
	UDataTable* ItemData;
	//

	UPROPERTY(Config)
	FSoftClassPath SkillSetPath;
	UPROPERTY()
	UDataTable* SkillSetData;

	UPROPERTY(Config)
	FSoftClassPath HeroSkillSetPath;
	UPROPERTY()
	UDataTable* HeroSkillSetData;


	UPROPERTY(Config)
	FSoftClassPath SummonDataPath;
	UPROPERTY()
	UDataTable* SummonData;


	UPROPERTY(Config)
	FSoftClassPath WeaponDataPath;
	UPROPERTY()
	UDataTable* WeaponData;

	UPROPERTY(Config)
	FSoftClassPath PotionDataPath;
	UPROPERTY()
	UDataTable* PotionData;

	UPROPERTY(Config)
	FSoftClassPath CrowdControlInfoDataPath;
	UPROPERTY()
	UDataTable* CrowdControlInfoData;

	UPROPERTY(Config)
	FSoftClassPath StatusEffectInfoDataPath;
	UPROPERTY()
	UDataTable* StatusEffectInfoData;

	int32 LastItemSerialID = INDEX_NONE;
	TArray<int32> ItemSerialIDList;

	UPROPERTY()
	TMap<FName, UDataTable*> DataTableMap;

	UPROPERTY()
	FGameDS_HeroCreateInfo HeroCreateInfo;
};

template <typename DataStruct>
const UDataTable* UGameDS_DataManager::GetDataTable()
{
	auto FindData = DataTableMap.Find(DataStruct::StaticStruct()->GetFName());
	return FindData ? *FindData : nullptr;
}

template <typename DataStruct>
const DataStruct* UGameDS_DataManager::GetDataInRow(int32 DataID)
{
	const UDataTable* FindData = GetDataTable<DataStruct>();
	if (FindData)
	{
		return FindData->FindRow<DataStruct>(FName(*FString::Printf(TEXT("%d"), DataID)), TEXT(""));
	}
	return nullptr;
}

template <typename DataStruct>
void UGameDS_DataManager::AddDataTable(UDataTable* DataTable)
{
	if(DataTable == nullptr)
		return;

	DataTableMap.Add(DataStruct::StaticStruct()->GetFName(), DataTable);
}