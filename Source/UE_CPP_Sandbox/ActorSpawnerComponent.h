// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ActorSpawnerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_CPP_SANDBOX_API UActorSpawnerComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorSpawnerComponent();

    UFUNCTION(BlueprintCallable, Category=CookBook)
    void Spawn();

    UPROPERTY(EditAnywhere)
    TSubclassOf<AActor> ActorToSpawn;

protected:
    void BeginPlay() override;
};
