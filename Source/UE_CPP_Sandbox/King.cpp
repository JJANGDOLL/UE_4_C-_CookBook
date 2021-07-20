// Fill out your copyright notice in the Description page of Project Settings.

#include "King.h"
#include <ConstructorHelpers.h>
#include <Engine/StaticMesh.h>

AKing::AKing()
{
    PrimaryActorTick.bCanEverTick = true;

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
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

void AKing::Die()
{
    OnKingDeath.Broadcast(this);
}
