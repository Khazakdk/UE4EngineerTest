// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseRobot.h"
#include "IDropperActor.h"
#include "..\Droppables\BaseDroppable.h"
#include "DropperRobot.generated.h"

/**
 * Used in conjuction with DropInstruction.  Provides a place to specifiy the mesh being dropped.
 */
UCLASS()
class AIRENGINEERTEST_API ADropperRobot : public ABaseRobot, public IIDropperActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
  TSubclassOf<ABaseDroppable> Droppable;

	virtual TSubclassOf<ABaseDroppable> GetDroppable_Implementation() override;
};
