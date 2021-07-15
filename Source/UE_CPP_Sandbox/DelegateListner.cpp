// Fill out your copyright notice in the Description page of Project Settings.

#include "DelegateListner.h"
#include "Kismet/GameplayStatics.h"
#include "UE_CPP_SandboxGameModeBase.h"
#include "Components/PointLightComponent.h"

// Sets default values
ADelegateListner::ADelegateListner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    PointLight = CreateDefaultSubobject<UPointLightComponent>("PointLight");
    RootComponent = PointLight;

    PointLight->SetVisibility(false);

    PointLight->SetLightColor(FLinearColor::Blue);
}

// Called when the game starts or when spawned
void ADelegateListner::BeginPlay()
{
	Super::BeginPlay();
	
    UWorld* TheWorld = GetWorld();
    if (TheWorld != nullptr)
    {
        AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

        AUE_CPP_SandboxGameModeBase* MyGameMode = Cast<AUE_CPP_SandboxGameModeBase>(GameMode);

        if (MyGameMode != nullptr)
        {
            MyGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListner::EnableLight);
        }
    }
}

// Called every frame
void ADelegateListner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateListner::EnableLight()
{
    PointLight->SetVisibility(true);
}

void ADelegateListner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    UWorld* TheWorld = GetWorld();
    if (TheWorld != nullptr)
    {
        AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);

        AUE_CPP_SandboxGameModeBase* MyGameMode = Cast<AUE_CPP_SandboxGameModeBase>(GameMode);
        if (MyGameMode != nullptr)
        {
            MyGameMode->MyStandardDelegate.Unbind();
        }
    }
}

