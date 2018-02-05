// Fill out your copyright notice in the Description page of Project Settings.

#include "Selectable.h"
#include "GameFramework/PawnMovementComponent.h"


// Sets default values
ASelectable::ASelectable()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASelectable::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASelectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASelectable::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

