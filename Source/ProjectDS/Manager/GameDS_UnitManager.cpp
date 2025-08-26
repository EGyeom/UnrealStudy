#include "GameDS_UnitManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameDS_CustomData.h"
#include "GameDS_DataManager.h"
#include "GameFramework/Character.h"

UGameDS_UnitManager::UGameDS_UnitManager()
{

}

void UGameDS_UnitManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}


void UGameDS_UnitManager::Deinitialize()
{
	Super::Deinitialize();
}

int32 UGameDS_UnitManager::SpawnCharacter()
{
	if (UGameDS_DataManager* DataManager = UGameInstance::GetSubsystem<UGameDS_DataManager>(GetGameInstance()))
	{
		const FGameDS_SpawnData* SpawnData = DataManager->GetSpawnData();
		const FTransform& SpawnDataTransform = DataManager->GetSpawnPointTransform(1);
		const FVector SpawnPositon = SpawnDataTransform.GetLocation();
		const FRotator SpawnDataRotator = SpawnDataTransform.Rotator();
		if (SpawnData == nullptr)
			return INDEX_NONE;

		AActor* Actor = GetWorld()->SpawnActor(SpawnData->CharacterBP, &SpawnPositon, &SpawnDataRotator);
	
	}
	return INDEX_NONE;
}
