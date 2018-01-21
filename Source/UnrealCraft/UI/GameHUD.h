// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCRAFT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

	TArray<class ASelectable*> GetSelection();

protected:
	FVector2D BoxStart;
	FVector2D BoxEnd;

	TArray<class ASelectable*> Selection;
};
