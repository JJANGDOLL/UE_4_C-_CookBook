// Fill out your copyright notice in the Description page of Project Settings.

#include "BarracksUnit.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ABarracksUnit::ABarracksUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    VisualRepresentation = CreateDefaultSubobject<UStaticMeshComponent>("UnitVisual");
    auto StaticMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
    if (StaticMesh.Succeeded())
    {
        VisualRepresentation->SetStaticMesh(StaticMesh.Object);
    }

    VisualRepresentation->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
    SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

// Called when the game starts or when spawned
void ABarracksUnit::BeginPlay()
{
	Super::BeginPlay();
	
    VisualRepresentation->AttachTo(RootComponent);
}

// Called every frame
void ABarracksUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    SetActorLocation(GetActorLocation() + FVector(3, 0, 0));
}

// Called to bind functionality to input
void ABarracksUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

