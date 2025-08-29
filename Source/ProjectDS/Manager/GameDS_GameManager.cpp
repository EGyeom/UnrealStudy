// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDS_GameManager.h"
#include "ProjectDS/GameInstanceHolder.h"
#include "Object/GameDS_ManagerObject.h"

UGameDS_GameManager::UGameDS_GameManager()
{
}

void UGameDS_GameManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	FConsoleCommandWithArgsDelegate ExecuteConsoleCommandDelegate;
	ExecuteConsoleCommandDelegate.BindUObject(this, &UGameDS_GameManager::ExecuteConsoleCommand);
	IConsoleManager::Get().RegisterConsoleCommand(
		TEXT("GameDS.ExecuteCommand"),
		TEXT("Execute a command in the game manager."),
		ExecuteConsoleCommandDelegate
	);

	bIsTickingObjects = GIsRunning;
}

void UGameDS_GameManager::Deinitialize()
{
}

void UGameDS_GameManager::Tick(float DeltaTime)
{
	for(UGameDS_ManagerObject* ManagerObject : ManagerObjectList)
	{
		ManagerObject->Tick(DeltaTime, FGameInstanceHolder::GetGameInstance());
	}
}

bool UGameDS_GameManager::IsTickable() const
{
	return bIsTickingObjects;
}

TStatId UGameDS_GameManager::GetStatId() const
{
	return Super::GetStatID();
}

void UGameDS_GameManager::ExecuteConsoleCommand(const TArray<FString>& Command)
{
	if (Command.IsEmpty())
		return;

	{
		if (Command[0].Compare(TEXT("ChangeDebugMode")) == 0)
		{

		}
	}
}
