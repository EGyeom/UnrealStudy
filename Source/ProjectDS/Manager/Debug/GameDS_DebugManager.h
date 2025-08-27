#pragma once

#include "ProjectDS/Manager/Object/GameDS_ManagerObject.h"
#include "GameDS_DebugManager.generated.h"

UCLASS()
class UGameDS_DebugManager : public UGameDS_ManagerObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void Tick(float DeltaTime, UGameInstance* InGameInstance) override;

};
