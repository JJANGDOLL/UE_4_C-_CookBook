// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE_CPP_SandboxGameModeBase.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelegateSignature, FLinearColor);
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature);

UCLASS()
class UE_CPP_SANDBOX_API AUE_CPP_SandboxGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
    AUE_CPP_SandboxGameModeBase();

    FStandardDelegateSignature MyStandardDelegate;
    FParamDelegateSignature MyParamaterDelegate;
    FMulticastDelegateSignature MyMulticastDelegate;
    

};
