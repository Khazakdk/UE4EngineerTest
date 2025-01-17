// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\RobotInstruction.h"
#include "DropInstruction.generated.h"

/**
 * Spawns a instance configurable mesh in front of an actor that implements IDropperActor
 */
UCLASS()
class AIRENGINEERTEST_API UDropInstruction : public URobotInstruction
{
	GENERATED_BODY()
	
	bool ExecuteInstruction(APawn* TargetPawn, FString Options) override;
};
