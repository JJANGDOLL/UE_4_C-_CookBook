// Fill out your copyright notice in the Description page of Project Settings.

#include "UE_CPP_Interface_GameMode.h"
#include "MyInterface.h"
#include "SingleInterfaceActor.h"
#include "EngineUtils.h"

void AUE_CPP_Interface_GameMode::BeginPlay()
{
    Super::BeginPlay();

    //FTransform SpawnLocation;
    //ASingleInterfaceActor* SpawnActor = GetWorld()->SpawnActor<ASingleInterfaceActor>(ASingleInterfaceActor::StaticClass(), SpawnLocation);
    //UClass* ActorClass = SpawnActor->GetClass();

    //if (ActorClass->ImplementsInterface(UMyInterface::StaticClass()))
    //{
    //    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Spawned actor implements interface!"));
    //}

    for (TActorIterator<AActor> It(GetWorld(), AActor::StaticClass()); It; ++It)
    {
        AActor* Actor = *It;
        IMyInterface* MyInterfaceInstance = Cast<IMyInterface>(Actor);

        if (MyInterfaceInstance)
        {
            MyInterfaceInstances.Add(MyInterfaceInstance);
        }
    }

    FString Message = FString::Printf(TEXT("%d actors implement the interface"), MyInterfaceInstances.Num());

    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, Message);
}
