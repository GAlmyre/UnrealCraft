// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "CameraPawn.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCRAFT_API ACameraPawn : public ASpectatorPawn
{
	GENERATED_BODY()
	
public:
	ACameraPawn();

	virtual void BeginPlay() override;

	// camera movement in X
	void MoveForward(float Value);

	// camera movement in Y
	void MoveRight(float Value);

protected:
	UPROPERTY(EditAnywhere, Category = "Camera")
	class UCameraComponent* MainCamera;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void ZoomIn();

	void ZoomOut();
};
