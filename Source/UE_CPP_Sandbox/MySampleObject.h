// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyUStruct.h"
#include "MySampleObject.generated.h"

/**
 * 
 */
UENUM()
enum CharacterStatus
{
    STPOPED         UMETA(DisplayName = "Stopped"),
    MOVING          UMETA(DisplayName = "Moving"),
    ATTACKING   UMETA(DisplayName = "Attacking")
};

UCLASS(Blueprintable, BlueprintType)
class UE_CPP_SANDBOX_API UMySampleObject : public UObject
{
    GENERATED_BODY()

public:
    UMySampleObject();

    UPROPERTY()
        float Prop1;

    UPROPERTY(EditAnywhere)
        float Prop2;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CustomProp)
        float Prop3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CustomProp)
        float Prop4;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stat)
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)
    TSubclassOf<UObject> UClassOfPlayer;

    UPROPERTY(EditAnywhere, meta=(MetaClass="GameMode"), Category = Unit)
    FStringClassReference UClassGameMode;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
    FMyUStruct myUStrt;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
    TEnumAsByte<CharacterStatus> status;

    UPROPERTY()
    UStaticMeshComponent* Mesh;
};