// Fill out your copyright notice in the Description page of Project Settings.

#include "MySampleGameMode.h"
#include "SampleActor.h"

void AMySampleGameMode::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("BEGIN PLAY"));

    FTransform SpawnLocation;

    //SpawnActor = GetWorld()->SpawnActor<ASampleActor>(ASampleActor::StaticClass(), SpawnLocation);

    //FTimerHandle Timer;
    //GetWorldTimerManager().SetTimer(Timer, this, &AMySampleGameMode::DestroyActorFunction, 10);
}

void AMySampleGameMode::DestroyActorFunction()
{
    SpawnActor->Destroy();
}
