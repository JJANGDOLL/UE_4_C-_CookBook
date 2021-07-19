// Fill out your copyright notice in the Description page of Project Settings.

#include "Selectable.h"

#include "Engine/Engine.h"

// Add default functionality here for any ISelectable functions that are not pure virtual.
bool ISelectable::IsSelectable()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Selectable"));
    return true;
}

bool ISelectable::TrySelect()
{
    GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, TEXT("Accepting Selection"));
    return  true;
}

void ISelectable::Deselect()
{
    unimplemented();
}

