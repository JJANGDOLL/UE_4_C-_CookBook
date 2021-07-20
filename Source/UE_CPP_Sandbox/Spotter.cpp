// Fill out your copyright notice in the Description page of Project Settings.

#include "Spotter.h"
#include <ConstructorHelpers.h>
#include <Engine/StaticMesh.h>
#include <DrawDebugHelpers.h>

ASpotter::ASpotter()
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
        SM->SetRelativeRotation(FRotator(90, 0, 0));
    }
}

void ASpotter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    
    auto EndLocation = GetActorLocation() + ActorToWorld().TransformVector(FVector(0, 0, -200));

    FHitResult HitResult;

    GetWorld()->SweepSingleByChannel(HitResult, GetActorLocation(), EndLocation, FQuat::Identity, ECC_Camera, FCollisionShape::MakeSphere(25), FCollisionQueryParams("Spot", true, this));

    APawn* SpottedPlayer = Cast<APawn>(HitResult.Actor.Get());

    if (SpottedPlayer != nullptr)
    {
        OnPlayerSpotted(SpottedPlayer);
    }

    DrawDebugLine(GetWorld(), GetActorLocation(), EndLocation, FColor::Red);
}
