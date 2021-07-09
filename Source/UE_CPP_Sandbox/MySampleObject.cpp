// Fill out your copyright notice in the Description page of Project Settings.

#include "MySampleObject.h"

UMySampleObject::UMySampleObject()
{
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
}