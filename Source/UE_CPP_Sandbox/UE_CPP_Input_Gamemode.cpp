// Fill out your copyright notice in the Description page of Project Settings.

#include "UE_CPP_Input_Gamemode.h"
#include "Blueprint/UserWidget.h"

void AUE_CPP_Input_Gamemode::BeginPlay()
{
    Super::BeginPlay();

    if (Widget)
    {
        UUserWidget* Menu = CreateWidget<UUserWidget>(GetWorld(), Widget);

        if (Menu)
        {
            Menu->AddToViewport();
            GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
        }
    }
}
