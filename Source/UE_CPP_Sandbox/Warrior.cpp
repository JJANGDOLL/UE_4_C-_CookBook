// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    lastInput = FVector2D::ZeroVector;
}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    check(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Forward", this, &AWarrior::Forward);
    PlayerInputComponent->BindAxis("Back", this, &AWarrior::Back);
    PlayerInputComponent->BindAxis("Left", this, &AWarrior::Left);
    PlayerInputComponent->BindAxis("Right", this, &AWarrior::Right);
}

void AWarrior::Forward(float amount)
{
    AddMovementInput(GetActorForwardVector(), amount);
    lastInput.Y + amount;
}

void AWarrior::Back(float amount)
{
    AddMovementInput(-GetActorForwardVector(), amount);
}

void AWarrior::Right(float amount)
{
    AddMovementInput(GetActorRightVector(), amount);
}

void AWarrior::Left(float amount)
{
    AddMovementInput(-GetActorRightVector(), amount);
}

