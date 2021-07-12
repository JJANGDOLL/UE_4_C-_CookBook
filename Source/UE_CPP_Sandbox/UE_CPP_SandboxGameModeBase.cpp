// Fill out your copyright notice in the Description page of Project Settings.

#include "UE_CPP_SandboxGameModeBase.h"
#include "InventoryCharacter.h"

AUE_CPP_SandboxGameModeBase::AUE_CPP_SandboxGameModeBase()
{
    UE_LOG(LogTemp, Warning, TEXT("Some warning Message"))
    DefaultPawnClass = AInventoryCharacter::StaticClass();
}