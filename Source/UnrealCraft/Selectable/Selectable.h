// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "Selectable.generated.h"

UCLASS()
class UNREALCRAFT_API ASelectable : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASelectable();

	UFUNCTION(BlueprintImplementableEvent, Category = "Selection")
	void ToggleSelectionWidget(bool bIsSelected);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
