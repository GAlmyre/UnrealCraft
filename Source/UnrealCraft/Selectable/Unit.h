// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Selectable/Selectable.h"
#include "Unit.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCRAFT_API AUnit : public ASelectable
{
	GENERATED_BODY()
	
	
public:

	AUnit();

	void BeginPlay();

	// the behavior tree used by the unit
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;
/*
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	class UUnitMovementComponent* MovementComp;
	*/
};