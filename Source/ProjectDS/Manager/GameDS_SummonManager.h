#pragma once
#include "Object/GameDS_ManagerObject.h"
#include "GameDS_SummonManager.generated.h"

UCLASS()
class UGameDS_SummonManager : public UGameDS_ManagerObject
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime, UGameInstance* InGameInstance) override;
};

