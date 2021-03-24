// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../RobotInstruction.h"
#include "MoveInstruction.generated.h"

/**
 * Moves the robot 100 units forward when executed
 */
UCLASS()
class AIRENGINEERTEST_API UMoveInstruction : public URobotInstruction
{
	GENERATED_BODY()
	
	bool ExecuteInstruction(APawn* TargetPawn, FString Options) override;
};
