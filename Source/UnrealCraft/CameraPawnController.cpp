// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawnController.h"
#include "CameraPawn.h"
#include "Selectable/Selectable.h"
#include "UI/GameHUD.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "AI/UnitController.h"

ACameraPawnController::ACameraPawnController()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsSelecting = false;
	CurrentOrder.OrderType = EOrderType::None;
}

void ACameraPawnController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
}

void ACameraPawnController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// draw the box in the HUD
	if (bIsSelecting)
	{
		if (AGameHUD* HUD = Cast<AGameHUD>(GetHUD()))
		{
			float MouseX, MouseY;
			GetMousePosition(MouseX, MouseY);
			SelectionEnd = FVector2D(MouseX, MouseY);
		}
	}
}

void ACameraPawnController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("StartSelection", IE_Pressed, this, &ACameraPawnController::Select);
	InputComponent->BindAction("StartSelection", IE_Released, this, &ACameraPawnController::StopSelection);
	InputComponent->BindAction("AddToSelection", IE_Released, this, &ACameraPawnController::StopAddToSelection);
	InputComponent->BindAction("Move", IE_Pressed, this, &ACameraPawnController::MoveOrder);
	InputComponent->BindAction("Attack", IE_Pressed, this, &ACameraPawnController::Attack);
	InputComponent->BindAction("Hold", IE_Pressed, this, &ACameraPawnController::Hold);
	InputComponent->BindAction("Patrol", IE_Pressed, this, &ACameraPawnController::Patrol);
	InputComponent->BindAction("Stop", IE_Pressed, this, &ACameraPawnController::Stop);
}

void ACameraPawnController::Select()
{
	UE_LOG(LogTemp, Warning, TEXT("StartSelection"))
	FHitResult HitResult;
	bIsSelecting = true;
	float MouseX, MouseY;
	GetMousePosition(MouseX, MouseY);
	SelectionStart = FVector2D(MouseX, MouseY);
}

void ACameraPawnController::StopSelection()
{
	UE_LOG(LogTemp, Warning, TEXT("StopSelection"))
	bIsSelecting = false;
	float MouseX, MouseY;
	GetMousePosition(MouseX, MouseY);
	SelectionEnd = FVector2D(MouseX, MouseY);

	if (AGameHUD* HUD = Cast<AGameHUD>(GetHUD()))
	{
		TArray<ASelectable*> TempSelection = HUD->GetSelection();

		for (size_t i = 0; i < CurrentSelection.Num(); i++)
		{
			CurrentSelection[i]->ToggleSelectionWidget(false);
		}
		CurrentSelection.Empty();

		for (size_t i = 0; i < TempSelection.Num(); i++)
		{
			CurrentSelection.Add(TempSelection[i]);
			CurrentSelection[i]->ToggleSelectionWidget(true);
		}
	}
}

void ACameraPawnController::AddToSelection()
{
}

void ACameraPawnController::StopAddToSelection()
{
	UE_LOG(LogTemp, Warning, TEXT("StopAddToSelection"))
	bIsSelecting = false;
	float MouseX, MouseY;
	GetMousePosition(MouseX, MouseY);
	SelectionEnd = FVector2D(MouseX, MouseY);

	if (AGameHUD* HUD = Cast<AGameHUD>(GetHUD()))
	{
		TArray<ASelectable*> TempSelection = HUD->GetSelection();

		for (size_t i = 0; i < TempSelection.Num(); i++)
		{
			CurrentSelection.Add(TempSelection[i]);
			TempSelection[i]->ToggleSelectionWidget(true);
		}
	}
}

void ACameraPawnController::MoveOrder()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		CurrentOrder.Location = Hit.ImpactPoint;

		CurrentOrder.OrderType = EOrderType::Move;

		for (size_t i = 0; i < CurrentSelection.Num(); i++)
		{
			AUnitController* Controller = Cast<AUnitController>(CurrentSelection[i]->GetController());
			Controller->ExecuteOrder(CurrentOrder);
		}
	}	
}