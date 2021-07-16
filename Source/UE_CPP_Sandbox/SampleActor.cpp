// Fill out your copyright notice in the Description page of Project Settings.

#include "SampleActor.h"

// Sets default values
ASampleActor::ASampleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    UE_LOG(LogTemp, Warning, TEXT("My Sample Actor"));

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");

    auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh> (TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    if (MeshAsset.Object != nullptr)
    {
        Mesh->SetStaticMesh(MeshAsset.Object);
    }

}

void ASampleActor::BeginPlay()
{
    Super::BeginPlay();
}

FString ASampleActor::UFuncString()
{
    return FString::Printf(TEXT("%s"), *Name);
}