// Fill out your copyright notice in the Description page of Project Settings.

#include "ParamDelegateListener.h"
#include "Components/PointLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UE_CPP_SandboxGameModeBase.h"

// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
    RootComponent = PointLight;
}

void AParamDelegateListener::SetLightColor(FLinearColor LightColor, bool EnableLight)
{
    PointLight->SetLightColor(LightColor);
    PointLight->SetVisibility(EnableLight);
}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();

    UWorld* TheWorld = GetWorld();
    if (TheWorld != nullptr)
    {
        AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

        AUE_CPP_SandboxGameModeBase* MyGameMode = Cast<AUE_CPP_SandboxGameModeBase>(GameMode);

        if (MyGameMode != nullptr)
        {
            MyGameMode->MyParamaterDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor, false);
        }
    }
}

// Called every frame
void AParamDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

