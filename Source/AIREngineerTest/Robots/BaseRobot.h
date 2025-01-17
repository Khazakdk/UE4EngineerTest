// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "..\RobotInstruction.h"
#include "BaseRobot.generated.h"

UCLASS()
class AIRENGINEERTEST_API ABaseRobot : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseRobot();

	void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USkeletalMeshComponent* RobotMesh;

	UPROPERTY(BlueprintReadWrite)
	float MovementRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FOptionsInstruction> Instructions;

protected:
	UFUNCTION(BlueprintCallable)
	void WalkForward();

	UFUNCTION(BlueprintCallable)
	void RunInstructions();
};
