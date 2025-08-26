// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameDS_CustomData.generated.h"

class ACharacter;

USTRUCT(BlueprintType)
struct FGameDS_SpawnData
{
	GENERATED_BODY()

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
