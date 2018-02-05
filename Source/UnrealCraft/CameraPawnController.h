// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CameraPawnController.generated.h"

UENUM(BlueprintType)
enum class EOrderType : uint8
{
	None, 
	Attack,
	Move, 
	Hold,
	Stop,
	Patrol
};

USTRUCT()
struct FOrder
{
	GENERATED_BODY()

	FVector Location;

	EOrderType OrderType;
};

/**
 * 
 */
UCLASS()
class UNREALCRAFT_API ACameraPawnController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ACameraPawnController();
	
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

	// where the player started drawing the selection box
	FVector2D SelectionStart;

	// where the player stopped drawing the selection box
	FVector2D SelectionEnd;

	// Is the player drawing a selection box
	bool bIsSelecting;

protected:
	void SetupInputComponent();

	// handle the start of a selection action
	void Select();

	// process the end of a selection action
	void StopSelection();

	// begin to try to add the units in the box to the current selection
	void AddToSelection();

	// end to try to add the unit under the cursor to the current selection
	void StopAddToSelection();

	void Attack() { CurrentOrder.OrderType = EOrderType::Attack; }

	void Hold() { CurrentOrder.OrderType = EOrderType::Hold; }

	void Patrol() { CurrentOrder.OrderType = EOrderType::Patrol; }

	void Stop() { CurrentOrder.OrderType = EOrderType::Stop; }

	void MoveOrder();

	// store the units selected by the player
	UPROPERTY(VisibleAnywhere, Category = "Selection")
	TArray<class ASelectable*> CurrentSelection;

	FOrder CurrentOrder;

	// resources
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Resources")
	int StoneCount = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Resources")
	int WoodCount = 0;

};
