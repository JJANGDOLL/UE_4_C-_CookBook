// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyInterface.h"
#include "UE_CPP_Interface_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_SANDBOX_API AUE_CPP_Interface_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    virtual void BeginPlay() override;

    TArray<IMyInterface*> MyInterfaceInstances;
};
