// Fill out your copyright notice in the Description page of Project Settings.

#include "CameraPawn.h"
#include "Camera/CameraComponent.h"

ACameraPawn::ACameraPawn()
{
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(RootComponent);
}

void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACameraPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACameraPawn::MoveRight);

	PlayerInputComponent->BindAction("ZoomOut", IE_Pressed, this, &ACameraPawn::ZoomOut);
	PlayerInputComponent->BindAction("ZoomIn", IE_Pressed, this, &ACameraPawn::ZoomIn);
}

void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();

	MainCamera->SetWorldRotation(FRotator(-60., 0., .0));
	SetActorLocation(FVector(0., 0., 1200.));

}

void ACameraPawn::MoveForward(float Value)
{
	if (Value != 0)
	{
		AddMovementInput(FVector(1., 0., 0.), Value * 1000);
	}
}

void ACameraPawn::MoveRight(float Value)
{
	if (Value != 0)
	{
		AddMovementInput(FVector(0., 1., 0.), Value * 1000);
	}
}

void ACameraPawn::ZoomIn()
{
	AddMovementInput(FVector(0., 0., -1.), 10000);
}

void ACameraPawn::ZoomOut()
{
	AddMovementInput(FVector(0., 0., 1.), 10000);
}


