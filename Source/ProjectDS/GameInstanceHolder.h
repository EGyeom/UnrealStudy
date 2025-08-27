#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Manager/GameDS_GameManager.h"

class FGameInstanceHolder
{
	static UGameInstance* GameDSInstance;
public:
	static UGameInstance* GetGameInstance()
	{
		if(GameDSInstance == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("GameDSInstance is null!"));	
		}
		return GameDSInstance;
	}
	static void SetGameInstance(UGameInstance* InGameInstance)
	{
		GameDSInstance = InGameInstance;
	}

	template<typename SubSystemClass>
	static SubSystemClass* GetSubSystem()
	{
		if(GameDSInstance == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("GameDSInstance is null!"));	
			return nullptr;
		}
		return GameDSInstance->GetSubsystem<SubSystemClass>();
	}

	template<typename ManagerClass>
	static ManagerClass* GetManager()
	{
		if(GameDSInstance == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("GameDSInstance is null!"));	
			return nullptr;
		}
		UGameDS_GameManager* GameManager = GameDSInstance->GetSubsystem<UGameDS_GameManager>();
	
		if(GameManager == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("GameManager is null!"));	
			return nullptr;
		}
		return GameManager->GetManagerObject<ManagerClass>();
	}

	static UWorld* GetWorld()
	{
		if (GameDSInstance == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("GameDSInstance is null!"));
			return nullptr;
		}
		return GameDSInstance->GetWorld();
	}
};

