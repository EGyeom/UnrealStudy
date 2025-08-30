// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "ProjectDS/Unit/GameDS_UnitDefine.h"
#include "ProjectDS/Skill/GameDS_SkillDefine.h"
#include "GameDS_CustomData.generated.h"

class ACharacter;
class AGameDS_Summon;
enum class EGameDS_HeroActionState : uint8;

USTRUCT(BlueprintType)
struct FGameDS_SpawnData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	EGameDS_UnitType UnitType;

	UPROPERTY(EditAnywhere)
	EGameDS_HeroClassType HeroClassType;

	UPROPERTY(EditAnywhere)
	int32 DataID = INDEX_NONE;

	UPROPERTY(EditAnywhere, meta = (DisplayThumbnail = true))
	TSubclassOf<ACharacter> CharacterBP;
};


UCLASS(Blueprintable, BlueprintType)
class UGameDS_SpawnUnitData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FGameDS_SpawnData> SpawnDataList;
};

USTRUCT(BlueprintType)
struct FGameDS_HeroStatConfigDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameDS_HeroStatInfo HeroStatInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameDS_HeroCreateInfo HeroCreateInfo;
};

USTRUCT(BlueprintType)
struct FGameDS_EnemyStatConfigDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameDS_UnitStatInfo UnitStatInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PhysicalAttackValue = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MagicalAttackValue = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SprintSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float FaceOffSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PatrolSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaximumChaseableDistance = 2500.0f;

};

USTRUCT(BlueprintType)
struct FGameDS_SkillDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SkillName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayThumbnail=true))
	UAnimMontage* SkillMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_SkillType SkillType = EGameDS_SkillType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CoolTime = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CriticalPercentage = 0.0f;

};

USTRUCT(BlueprintType)
struct FGameDS_SkillInfoDataTable : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SkillInfoName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CollisionInfoID = INDEX_NONE;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> CrowdControlInfoIDList;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageValue = 0.0f;
};

USTRUCT(BlueprintType)
struct FGameDS_CollisionInfoDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CollisionInfoID = INDEX_NONE;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_CollisionShape CollisionShape = EGameDS_CollisionShape::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_SkillSpawnType CollisionSpawnType = EGameDS_SkillSpawnType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Param0 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Param1 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Param2 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Param3 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Param4 = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Param5 = 0.0f;

};

UENUM(BlueprintType)
enum class EGameDS_EnemySkillType : uint8
{
	None = 0,
	Normal,
	ForwardSpecial,
	BackwardSpecial
	FaceOff,
	Num,
};

USTRUCT(BlueprintType)
struct FGameDS_EnemySkillSettingDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_EnemySkillType SkillType = EGameDS_EnemySkillType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WaitCount = INDEX_NONE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinDistance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDistance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinAngleDifference = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotateSpeedFactor = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveBlockDuration = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackBlockDuration = 0.0f;
};

UENUM(BlueprintType)
enum class EGameDS_ItemType : uint8
{
	None = 0,
	Potion,
	Weapon
};

USTRUCT(BlueprintType)
struct FGameDS_ItemDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_ItemType ItemType = EGameDS_ItemType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh* ItemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* ItemIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString ItemDescription;
};

USTRUCT(BlueprintType)
struct FGameDS_SkillSetDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SkillSetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> SkillSet;
};

UENUM(BlueprintType)
enum class EGameDS_SummonType : uint8
{
	None = 0,
	Default,
	Follower
};

USTRUCT(BlueprintType)
struct FGameDS_SummonDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_SummonType SummonType = EGameDS_SummonType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName SummonName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_SkillSpawnType SpawnType = EGameDS_SkillSpawnType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SkillInfoID = INDEX_NONE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SummonSpeed = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SummonDuration = INDEX_NONE;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayThumbnail=true))
	TSubclassOf<AGameDS_Summon> SummonBP = nullptr;
};

UENUM(BlueprintType)
enum class EGameDS_GripType : uint8
{
	None,
	OneHand,
	TwoHand
};

UENUM(BlueprintType)
enum class EGameDS_WeaponType : uint8
{
	None,
	Axe,
	Sword,
	Shield,
	LongSword
};

UENUM(BlueprintType)
enum class EGameDS_WeaponSpawnType : uint8
{
	None,
	LeftWeapon,
	RightWeapon,
	LeftShield,
	RightShield
};

USTRUCT(BlueprintType)
struct FGameDS_WeaponDataTable : public FGameDS_ItemDataTable
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WeaponID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_GripType GripType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_WeaponType WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_WeaponSpawnType SpawnType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayThumbnail=true))
	TSubclassOf<UGameDS_UnitAnimInstance> UnitAnim = nullptr;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayThumbnail = true))
	TMap<FString,UAnimMontage*> Montages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredVaitality = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredEndurance = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredStrength = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RequiredIntelligence = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PhysicalDamage = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MagicDamage = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PhysicalGuard = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MagicGuard = 0.0f;
};

USTRUCT(BlueprintType)
struct FGameDS_PotionDataTable : public FGameDS_ItemDataTable
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 DefaultUseCount = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DefaultHealValue = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CoolTime = 5.0f;
};

UENUM(BlueprintType)
enum class EGameDS_CrowdControlType : uint8
{
	None = 0,
	PushBack,
	Stun,
	Num
};

UENUM(BlueprintType)
enum class EGameDS_CrowdControlMoveType : uint8
{
	None = 0,
	CasterToTarget,
	TargetToCaster,
	SummonToTarget,
	SummonToCaster,
	Num
};

USTRUCT(BlueprintType)
struct FGameDS_CrowdControlData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_CrowdControlType CrowdControlType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameDS_CrowdControlMoveType CrowdControlMoveType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Distance = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveBlockDuration = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ActionBlockDuration = 0.0f;
};

USTRUCT(BlueprintType)
struct FGameDS_CrowdControlInfoDataTable : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CrowdControlName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameDS_CrowdControlData CrowdControlData;
};
