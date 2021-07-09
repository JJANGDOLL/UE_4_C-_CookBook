// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorComponentLayer.generated.h"

UCLASS()
class UE_CPP_SANDBOX_API AActorComponentLayer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorComponentLayer();

    UPROPERTY(VisibleAnywhere)
    USceneComponent* Root;

    UPROPERTY(VisibleANywhere)
    USceneComponent* ChildSceneComponent;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BoxOne;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* BoxTwo;

};
