// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MySampleGameMode.generated.h"

/**
 * 
 */
class ASampleActor;

UCLASS(BlueprintType)
class UE_CPP_SANDBOX_API AMySampleGameMode : public AGameModeBase
{
	GENERATED_BODY()

    ASampleActor* SpawnActor;
	
public:
    void BeginPlay() override;
    void DestroyActorFunction();
};
