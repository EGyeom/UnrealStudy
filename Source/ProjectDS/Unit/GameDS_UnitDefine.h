#pragma once
#include "ProjectDS/Skill/GameDS_SkillDefine.h"
#include "GameDS_UnitDefine.generated.h"

struct FGameDS_SummonDataTable;
enum class EGameDS_DamageType : uint8;

UENUM(BlueprintType)
enum class EGameDS_UnitType : uint8
{
	None,
	Hero,
	Enemy,
	Boss,
	SummonObject,
};

UENUM(BlueprintType)
enum class EGameDS_HeroClassType : uint8
{
    None,
    Warrior,
    Archer,
    Mage,
    Thief,
};

UENUM(BlueprintType)
enum class EGameDS_HeroAnimNotifyState : uint8
{
    Movable = 0,
    Attackable,
    Attacking
};

UENUM(BlueprintType)
enum class EGameDS_HeroActionType : uint8
{
    None = 0,
    Look,
    Move,
    Jump,
    NormalAttack,
    SpecialAttack,
    Evade,
    Defense,
    Menu,
    Inventory,
    Status,
    ChangeItem,
    DrinkPotion,
    Interaction
}

enum class EGameDS_StatType : uint8
{
    None = 0,
    Health,
    Stamina,
    MaximumHealth,
    MaximumStamina
};

enum class EGameDS_StatResult : uint8
{
    None = 0,
    ZeroHealth,
    ZeroStamina,
    FullHealth,
    FullStamina
};

UENUM(BlueprintType)
enum class EGameDS_CreateWeaponType : uint8
{
    None = 0,
    Sword,
    Axe,
    Staff,
    Dagger
};


UENUM(BlueprintType)
enum class EGameDS_GenderType : uint8
{
    Male,
    Female,
    Other
}

USTRUCT(BlueprintType)
struct FGameDS_UnitStatInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Health = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float Stamina = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float PhysicalDefense = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    float MagicalDefense = INDEX_NONE;
};

USTRUCT(BlueprintType)
struct FGameDS_HeroStatInfo : FGameDS_UnitStatInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroStats")
    int32 Level = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroStats")
    float VitalityPoint = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroStats")
    float EndurancePoint = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroStats")
    float StrengthPoint = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroStats")
    float IntelligencePoint = INDEX_NONE;
};

USTRUCT(BlueprintType)
struct FGameDS_HeroCreateInfo
{
    GENERATED_BODY()


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroCreate")
    FString Name = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroCreate")
    EGameDS_GenderType Gender = EGameDS_GenderType::Male;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroCreate")
    EGameDS_CreateWeaponType WeaponType = EGameDS_CreateWeaponType::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeroCreate")
    int32 SpawnPoint = INDEX_NONE;

    int32 LHandIndex = INDEX_NONE;
    int32 RHandIndex = INDEX_NONE;
    int32 PotionIndex = INDEX_NONE;

    TArray<FString> LHandItemList;
    TArray<FString> RHandItemList;
    TArray<FString> PotionItemList;
    TArray<FString> InventoryItemList;

    TArray<FString> HeroStatList;
}

USTRUCT(BlueprintType)
struct FGameDS_UnitSpawnOption
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
    EGameDS_UnitType UnitType = EGameDS_UnitType::None;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
    int32 UnitID = INDEX_NONE;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
    int32 DataID = INDEX_NONE;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
    int32 SpawnPoint = INDEX_NONE;
    

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
    FVector SpawnLocation = FVector::ZeroVector;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn")
    FRotator SpawnRotation = FRotator::ZeroRotator;

    bool bBattleMode = false;
    bool bUsePatrol = false;
    TArray<FVector> SplinePathPoints;
}

struct FGameDS_SummonUnitSpawnOption
{
    int32 OwnerUnitID = INDEX_NONE;
    int32 TargetUnitID = INDEX_NONE;
    int32 SummonUnitID = INDEX_NONE;
    int32 SummonDataID = INDEX_NONE;

    FVector SpawnLocation = FVector::ZeroVector;
    FRotator SpawnRotation = FRotator::ZeroRotator;
}


struct FGameDS_DamageInfo
{
    int32 AttackedUnitID = INDEX_NONE;
    int32 AttackedSummonUnitID = INDEX_NONE;
    int32 DamageAmount = 0;
    EGameDS_DamageType DamageType = EGameDS_DamageType::None;
    FVector HitLocation = FVector::ZeroVector;
    FVector HitNormal = FVector::ZeroVector;
}


UENUM(BlueprintType)
enum class EGameDS_UnitAnimType : uint8
{
	None = 0,
	NormalAttack,
	SpecialAttack,
	Dash,
	Die,
	ModeTransition,
	Num
};


UENUM(BlueprintType)
enum class EGameDS_ArrowKey : uint8
{
	Left = 0,
	Right,
	Up,
	Down
};

UENUM(BlueprintType)
enum class EGameDS_FootStepType : uint8
{
	None=0,
	Left,
	Right,
	Both
};