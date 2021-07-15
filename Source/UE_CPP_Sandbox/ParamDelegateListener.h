// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParamDelegateListener.generated.h"

class UPointLightComponent;
UCLASS()
class UE_CPP_SANDBOX_API AParamDelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AParamDelegateListener();

    UFUNCTION()
    void SetLightColor(FLinearColor LightColor);

    UPROPERTY()
    UPointLightComponent* PointLight;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
