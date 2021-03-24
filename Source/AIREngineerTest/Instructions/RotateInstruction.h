// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../RobotInstruction.h"
#include "RotateInstruction.generated.h"

/**
 * Rotates a pawn +90 degrees when executed
 */
UCLASS()
class AIRENGINEERTEST_API URotateInstruction : public URobotInstruction
{
	GENERATED_BODY()
	
	bool ExecuteInstruction(APawn* TargetPawn, FString Options) override;
};
