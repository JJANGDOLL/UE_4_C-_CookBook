// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SampleActor.generated.h"

UCLASS()
class UE_CPP_SANDBOX_API ASampleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASampleActor();

    void BeginPlay() override;

public:
    //UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyUFuncParam)
    //FString Name;

    //UFUNCTION(BlueprintCallable, Category=MyUFunc)
    //FString UFuncString();

    UPROPERTY()
    UStaticMeshComponent* Mesh;
};
