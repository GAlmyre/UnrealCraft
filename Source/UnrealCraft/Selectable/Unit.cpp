// Fill out your copyright notice in the Description page of Project Settings.

#include "Unit.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "../AI/UnitMovementComponent.h"

AUnit::AUnit()
{
	//MovementComp = CreateDefaultSubobject<UUnitMovementComponent>(TEXT("MovementComp"));
}

void AUnit::BeginPlay()
{
	Super::BeginPlay();

}
