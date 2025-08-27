// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/GameInstance.h"
#include "GameDS_Instance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTDS_API UGameDS_Instance : public UGameInstance
{
	GENERATED_BODY()

public:
	UGameDS_Instance();
	virtual void Init() override;
	virtual void Shutdown() override;
};
