// Fill out your copyright notice in the Description page of Project Settings.

#include "EventHandlerVolListener.h"
#include "Components/PointLightComponent.h"
#include "EventHandler.h"

// Sets default values
AEventHandlerVolListener::AEventHandlerVolListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
    RootComponent = PointLight;
}

void AEventHandlerVolListener::OnTriggerEvent()
{
    PointLight->SetLightColor(FLinearColor(0, 1, 0, 1));
}

// Called when the game starts or when spawned
void AEventHandlerVolListener::BeginPlay()
{
	Super::BeginPlay();
	
    if (TriggerEventSource != nullptr)
    {
        TriggerEventSource->OnPlayerEntered.AddUObject(this, &AEventHandlerVolListener::OnTriggerEvent);
    }
}

// Called every frame
void AEventHandlerVolListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

