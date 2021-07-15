// Fill out your copyright notice in the Description page of Project Settings.

#include "EventHandler.h"
#include "Kismet/GameplayStatics.h"
#include "UE_CPP_SandboxGameModeBase.h"

// Sets default values
AEventHandler::AEventHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    TriggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
    TriggerZone->SetBoxExtent(FVector(200, 200, 100));
}

// Called when the game starts or when spawned
void AEventHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEventHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEventHandler::NotifyActorBeginOverlap(AActor * OtherActor)
{
    auto Message = FString::Printf(TEXT("%s entered me"), *(OtherActor->GetName()));

    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);

    UWorld* TheWorld = GetWorld();
    if (TheWorld != nullptr)
    {
        AGameModeBase* GameMode = UGameplayStatics::GetGameMode(TheWorld);
        AUE_CPP_SandboxGameModeBase* MyGameMode = Cast<AUE_CPP_SandboxGameModeBase>(GameMode);

        if (MyGameMode != nullptr)
        {
            MyGameMode->MyStandardDelegate.ExecuteIfBound();
        }
    }
}

void AEventHandler::NotifyActorEndOverlap(AActor * OtherActor)
{
    auto Message = FString::Printf(TEXT("%s left me "), *(OtherActor->GetName()));

    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, Message);
}

