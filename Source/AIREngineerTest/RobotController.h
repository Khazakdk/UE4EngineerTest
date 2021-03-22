// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "RobotController.generated.h"

/**
 * AI Controller that supports basic movement for BaseRobot
 */
UCLASS()
class AIRENGINEERTEST_API ARobotController : public AAIController
{
	GENERATED_BODY()
	
public:
	ARobotController();
};
