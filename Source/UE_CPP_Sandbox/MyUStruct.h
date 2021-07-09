#pragma once

#include "ObjectMacros.h"
#include "MyUStruct.generated.h"

USTRUCT(Blueprintable)
struct FMyUStruct
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
    UTexture* Texture;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
    FLinearColor Color;
};