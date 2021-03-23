// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\RobotInstruction.h"
#include "DocumentInstruction.generated.h"

/**
 * Takes a screenshot from the currently possessed pawn, and outputs a text file listing the actors on screen if a droppable is found,
 * then destroys the droppable.
 */
UCLASS()
class AIRENGINEERTEST_API UDocumentInstruction : public URobotInstruction
{
	GENERATED_BODY()
	
	bool ExecuteInstruction(APawn* TargetPawn) override;

protected:
	void CreateReport(TArray<AActor*> actors, int reportNumber);
};
