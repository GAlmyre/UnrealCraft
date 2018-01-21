// Fill out your copyright notice in the Description page of Project Settings.

#include "UnitController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "../Selectable/Unit.h"

AUnitController::AUnitController()
{
	// Initialize blackboard and behavior tree
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	// Initialize blackboard keys
	OrderLocationKey = "OrderLocation";
}

void AUnitController::ExecuteOrder(FOrder Order)
{

	switch (Order.OrderType)
	{
	case EOrderType::Attack: 
		BlackboardComp->SetValueAsVector(OrderLocationKey, Order.Location);
		break;
	case EOrderType::Move:
		BlackboardComp->SetValueAsVector(OrderLocationKey, Order.Location);
		break;
	case EOrderType::Hold:
		BlackboardComp->SetValueAsVector(OrderLocationKey, Order.Location);
		break;
	case EOrderType::Patrol:
		BlackboardComp->SetValueAsVector(OrderLocationKey, Order.Location);
		break;
	case EOrderType::Stop:
		BlackboardComp->SetValueAsVector(OrderLocationKey, Order.Location);
		break;
	default:
		break;
	}
}

void AUnitController::Possess(APawn * Pawn)
{
	Super::Possess(Pawn);

	AUnit* Unit = Cast<AUnit>(Pawn);
	if (Unit)
	{
		if (Unit->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*(Unit->BehaviorTree->BlackboardAsset));
		}

		BehaviorComp->StartTree(*Unit->BehaviorTree);
	}
}
