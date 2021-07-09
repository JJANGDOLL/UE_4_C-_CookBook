// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorComponentLayer.h"

// Sets default values
AActorComponentLayer::AActorComponentLayer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>("Root");
    ChildSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
    BoxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
    BoxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh> (TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

    if (MeshAsset.Succeeded())
    {
        BoxOne->SetStaticMesh(MeshAsset.Object);
        BoxTwo->SetStaticMesh(MeshAsset.Object);
    }

    RootComponent = Root;
    BoxOne->AttachTo(Root);
    ChildSceneComponent->AttachTo(Root);

    BoxTwo->AttachTo(ChildSceneComponent);

    ChildSceneComponent->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(250, 0, 0), FVector(0.1f)));
}

