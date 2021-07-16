// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE_CPP_Input_Gamemode.generated.h"

/**
 * 
 */
UCLASS()
class UE_CPP_SANDBOX_API AUE_CPP_Input_Gamemode : public AGameModeBase
{
	GENERATED_BODY()


public:
    void BeginPlay();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<class UUserWidget> Widget;

    UFUNCTION(BlueprintCallable, Category = UIFuncs)
    void ButtonClicked()
    {
        UE_LOG(LogTemp, Warning, TEXT("UI Button Clicked"));
    }
};
