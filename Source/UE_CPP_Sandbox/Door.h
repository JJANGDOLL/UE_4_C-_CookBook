// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interactable.h"
#include "Openable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_SANDBOX_API ADoor : public AStaticMeshActor, public IInteractable, public IOpenable
{
	GENERATED_BODY()
public:
    ADoor();

    UFUNCTION()
    virtual bool CanInteract_Implementation() override;

    UFUNCTION()
    virtual void PerformInteract_Implementation() override;

    UFUNCTION()
    virtual void Open_Implementation() override;
};
