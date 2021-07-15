// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EventHandlerVolListener.generated.h"

class UPointLightComponent;
class AEventHandler;

UCLASS()
class UE_CPP_SANDBOX_API AEventHandlerVolListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEventHandlerVolListener();

    UPROPERTY()
    UPointLightComponent* PointLight;

    UPROPERTY(EditAnywhere)
    AEventHandler* TriggerEventSource;

    UFUNCTION()
    void OnTriggerEvent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
