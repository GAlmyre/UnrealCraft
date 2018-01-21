// Fill out your copyright notice in the Description page of Project Settings.

#include "GameHUD.h"
#include "CameraPawnController.h"
#include "Selectable/Selectable.h"

void AGameHUD::DrawHUD()
{
	Super::DrawHUD();
	if (ACameraPawnController* Controller = Cast<ACameraPawnController>(GetOwningPlayerController()))
	{
		if (Controller->bIsSelecting)
		{
			// Draw the selection box
			BoxStart = Controller->SelectionStart;
			BoxEnd = Controller->SelectionEnd;
			float Width = BoxEnd.X - BoxStart.X;
			float Height = BoxEnd.Y - BoxStart.Y;
			DrawRect(FLinearColor(0., 0.8, 0., 0.5), BoxStart.X, BoxStart.Y, Width, Height);

			Selection.Empty();
			// send the selected actors to the controller
			GetActorsInSelectionRectangle(BoxStart, BoxEnd, Selection, false, false);
		}	
	}
}

TArray<class ASelectable*> AGameHUD::GetSelection()
{
	return Selection;
}
