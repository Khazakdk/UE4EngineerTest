// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\RobotInstruction.h"
#include "DropInstruction.generated.h"

/**
 * 
 */
UCLASS()
class AIRENGINEERTEST_API UDropInstruction : public URobotInstruction
{
	GENERATED_BODY()
	
	bool ExecuteInstruction(APawn* TargetPawn, FString Options) override;
};
