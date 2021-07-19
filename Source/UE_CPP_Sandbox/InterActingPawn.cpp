// Fill out your copyright notice in the Description page of Project Settings.

#include "InterActingPawn.h"
#include "Interactable.h"
#include "Camera/PlayerCameraManager.h"
#include "CollisionQueryParams.h"
#include "WorldCollision.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerInput.h"

// Sets default values
AInterActingPawn::AInterActingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AInterActingPawn::TryInteract()
{
    APlayerController* MyController = Cast<APlayerController>(Controller);

    if(MyController)
    {
        APlayerCameraManager* MyCameraManager = MyController->PlayerCameraManager;
        auto StartLocation = MyCameraManager->GetCameraLocation();
        auto EndLocation = StartLocation + (MyCameraManager->GetActorForwardVector() * 100);

        FCollisionObjectQueryParams Params;
        FHitResult HitResult;


        GetWorld()->SweepSingleByObjectType(HitResult, StartLocation, EndLocation, FQuat::Identity,
                                            FCollisionObjectQueryParams(FCollisionObjectQueryParams::AllObjects),
                                            FCollisionShape::MakeSphere(25),
                                            FCollisionQueryParams(FName("Interaction"), true, this));

        if(HitResult.Actor != nullptr)
        {
            auto Class = HitResult.Actor->GetClass();
            if(Class->ImplementsInterface(UInteractable::StaticClass()))
            {
                if(IInteractable::Execute_CanInteract(HitResult.Actor.Get()))
                {
                    IInteractable::Execute_PerformInteract(HitResult.Actor.Get());
                }
            }
        }
    }
}

// Called to bind functionality to input
void AInterActingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    const FInputActionKeyMapping InterActKey("Interact", EKeys::T, 0, 0, 0, 0);

    PlayerInputComponent->BindAction("Interact", IE_Released, this, &AInterActingPawn::TryInteract);

    GetWorld()->GetFirstPlayerController()->PlayerInput->AddActionMapping(InterActKey);
}

