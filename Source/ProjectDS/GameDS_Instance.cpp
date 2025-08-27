// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDS_Instance.h"
#include "GameInstanceHolder.h"

UGameDS_Instance::UGameDS_Instance()
{

}

void UGameDS_Instance::Init()
{
	Super::Init();
	FGameInstanceHolder::SetGameInstance(this);
}

void UGameDS_Instance::Shutdown()
{
	Super::Shutdown();
	FGameInstanceHolder::SetGameInstance(nullptr);
}
