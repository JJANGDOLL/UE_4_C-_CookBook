// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Talker.h"
#include "TalkingMesh.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_SANDBOX_API ATalkingMesh : public AStaticMeshActor, public ITalker
{
	GENERATED_BODY()
public:
    ATalkingMesh();
    virtual void StartTalking_Implementation() override;
};
