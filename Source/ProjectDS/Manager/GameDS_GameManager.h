// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameDS_GameManager.generated.h"

class UGameDS_ManagerObject;

/**
 * 
 */
UCLASS()
class PROJECTDS_API UGameDS_GameManager : public UGameInstanceSubsystem, public FTickableGameObject
{
	GENERATED_BODY()
	
public:
	UGameDS_GameManager();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	virtual void Tick(float DeltaTime) override;
	virtual bool IsTickable() const override;
	virtual TStatId GetStatId() const override;

	template<typename ManagerClass>
	ManagerClass* GetManagerObject() const;

	void ExecuteConsoleCommand(const TArray<FString>& Command);

private:
	UPROPERTY()
	TArray<UGameDS_ManagerObject*> ManagerObjectList;

	bool bIsTickingObjects = false;
};



template<typename ManagerClass>
ManagerClass* UGameDS_GameManager::GetManagerObject() const
{
	for (UGameDS_ManagerObject* ManagerObject : ManagerObjectList)
	{
		if (ManagerObject->IsA<ManagerClass>())
		{
			return Cast<ManagerClass>(ManagerObject);
		}
	}
	return nullptr;
}
