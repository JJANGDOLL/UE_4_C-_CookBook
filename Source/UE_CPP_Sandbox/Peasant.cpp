// Fill out your copyright notice in the Description page of Project Settings.

#include "Peasant.h"
#include <ConstructorHelpers.h>
#include <Engine/StaticMesh.h>
#include "King.h"
#include <Engine/Engine.h>

APeasant::APeasant()
{
    PrimaryActorTick.bCanEverTick = true;

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

    UStaticMeshComponent* SM = GetStaticMeshComponent();
    if (SM != nullptr)
    {
        if (MeshAsset.Object != nullptr)
        {
            SM->SetStaticMesh(MeshAsset.Object);
            SM->SetGenerateOverlapEvents(true);
        }

        SM->SetMobility(EComponentMobility::Movable);
    }
}

void APeasant::Flee(AKing* DeadKing)
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Waily Waily!"));

    FVector FleeVector = GetActorLocation() - DeadKing->GetActorLocation();

    FleeVector.Normalize();
    FleeVector *= 500;
    SetActorLocation(GetActorLocation() + FleeVector);
}
