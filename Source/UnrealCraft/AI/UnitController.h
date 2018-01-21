// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Core/Public/Containers/Queue.h"
#include "CameraPawnController.h"
#include "UnitController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCRAFT_API AUnitController : public AAIController
{
	GENERATED_BODY()
	
public:
	AUnitController();

	void ExecuteOrder(FOrder Location);

	FORCEINLINE class UBehaviorTreeComponent* GetBehaviorComp() const { return BehaviorComp; }

	FORCEINLINE class UBlackboardComponent* GetBlackboardComp() const { return BlackboardComp; }

	virtual void Possess(APawn* Pawn) override;
protected:
	// the behavior tree to be run for this unit
	UPROPERTY()
	UBehaviorTreeComponent* BehaviorComp;
	
	// the blackboard to be used for this unit
	UPROPERTY()
	UBlackboardComponent* BlackboardComp;

	// A queue to store the orders given to this unit
	TQueue<FOrder, EQueueMode::Spsc> OrderQueue;

	/*Blackboard keys*/
	UPROPERTY(EditDefaultsOnly, Category = AI)
	FName OrderLocationKey;
};
