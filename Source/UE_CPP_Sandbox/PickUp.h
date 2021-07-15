// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.generated.h"

DECLARE_DELEGATE(FPickedupEventSignature)

class URotatingMovementComponent;

UCLASS()
class UE_CPP_SANDBOX_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

    virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

    UPROPERTY()
    UStaticMeshComponent* MyMesh;

    UPROPERTY()
    URotatingMovementComponent* RotatingComponent;

    FPickedupEventSignature OnPickedUp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
