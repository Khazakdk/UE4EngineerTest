// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseRobot.h"
#include "IGrabberActor.h"
#include "GrabberRobot.generated.h"

/**
 * 
 */
UCLASS()
class AIRENGINEERTEST_API AGrabberRobot : public ABaseRobot, public IIGrabberActor
{
	GENERATED_BODY()

public:
	virtual int GetDocumentCount_Implementation() override;

	UPROPERTY(BlueprintReadOnly)
	int DocumentCount = 1;
	
};
