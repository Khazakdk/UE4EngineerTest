// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RobotInstruction.generated.h"

USTRUCT(BlueprintType)
struct FOptionsInstruction
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<URobotInstruction> Instruction;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Options;
};

/*  */
UCLASS(Blueprintable)
class AIRENGINEERTEST_API URobotInstruction : public UObject
{
	GENERATED_BODY()

public:
	URobotInstruction();	

	UFUNCTION(BlueprintCallable)
	virtual bool ExecuteInstruction(APawn* TargetPawn, FString Options="");
};
