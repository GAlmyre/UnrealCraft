// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"

ABuilding::ABuilding()
{
	BuildingUI = CreateDefaultSubobject<UUserWidget>(TEXT("BuildingWidget"));

	BuildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(BuildingMesh);
}


