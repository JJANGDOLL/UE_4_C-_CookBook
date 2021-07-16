// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"
#include "GameFramework/PlayerInput.h"
#include "UE_CPP_Input_Gamemode.h"

// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    LastInput = FVector2D::ZeroVector;




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

    float len = LastInput.Size();

    if (len > 1.f)
    {
        LastInput /= len;
    }

    AddMovementInput(GetActorForwardVector(), LastInput.Y);
    AddMovementInput(GetActorRightVector(), LastInput.X);

    LastInput = FVector2D(0.f, 0.f);
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
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AWarrior::Jump);
    

    FInputAxisKeyMapping forwardKey("Forward", EKeys::W, 1.f);
    FInputAxisKeyMapping backKey("Back", EKeys::S, 1.f);
    FInputAxisKeyMapping rightKey("Right", EKeys::D, 1.f);
    FInputAxisKeyMapping leftKey("Left", EKeys::A, 1.f);
    FInputActionKeyMapping hotKey("S_HotKey", EKeys::E, 0, 0, 0, 0);
    FInputActionKeyMapping jumpKey("Jump", EKeys::SpaceBar, 0, 0, 0, 0);

    GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(forwardKey);
    GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(backKey);
    GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(rightKey);
    GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(leftKey);
    GetWorld()->GetFirstPlayerController()->PlayerInput->AddActionMapping(jumpKey);
    GetWorld()->GetFirstPlayerController()->PlayerInput->AddActionMapping(hotKey);

    auto GameMode = Cast<AUE_CPP_Input_Gamemode>(GetWorld()->GetAuthGameMode());
    auto Func = &AUE_CPP_Input_Gamemode::ButtonClicked;

    if (GameMode && Func)
    {
        PlayerInputComponent->BindAction("S_HotKey", IE_Pressed, GameMode, Func);
    }
}

void AWarrior::Forward(float amount)
{
    //AddMovementInput(GetActorForwardVector(), amount);
    LastInput.Y += amount;
}

void AWarrior::Back(float amount)
{
    //AddMovementInput(-GetActorForwardVector(), amount);
    LastInput.Y -= amount;
}

void AWarrior::Right(float amount)
{
    //AddMovementInput(GetActorRightVector(), amount);
    LastInput.X += amount;
}

void AWarrior::Left(float amount)
{
    //AddMovementInput(-GetActorRightVector(), amount);
    LastInput.X -= amount;
}

