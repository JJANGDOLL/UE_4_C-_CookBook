// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelectableCube.h"
#include "NonSelectableCube.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_SANDBOX_API ANonSelectableCube : public ASelectableCube
{
	GENERATED_BODY()

public:
    virtual bool IsSelectable() override;
    virtual bool TrySelect() override;
    virtual void Deselect() override;
};
