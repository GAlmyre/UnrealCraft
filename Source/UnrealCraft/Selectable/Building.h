// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UserWidget.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "Selectable/Selectable.h"
#include "Building.generated.h"

USTRUCT()
struct FResearch
{
	GENERATED_BODY()

	float ResearchTime;

	FName ResearchName;
};

/**
 * 
 */
UCLASS()
class UNREALCRAFT_API ABuilding : public ASelectable
{
	GENERATED_BODY()
	
public:
	ABuilding();

protected:

	TArray<FResearch> Researchs;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	UUserWidget* BuildingUI;

	UPROPERTY(EditDefaultsOnly, Category = "Mesh")
	UStaticMeshComponent* BuildingMesh;
};
