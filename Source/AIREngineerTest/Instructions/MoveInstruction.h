// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../RobotInstruction.h"
#include "MoveInstruction.generated.h"

/**
 * Moves the robot X units forward when executed.  X defaults to 100 or can be provided in the Options argument
 */
UCLASS()
class AIRENGINEERTEST_API UMoveInstruction : public URobotInstruction
{
	GENERATED_BODY()
	
	bool ExecuteInstruction(APawn* TargetPawn, FString Options) override;
};
