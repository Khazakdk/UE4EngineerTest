// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "..\Droppables\BaseDroppable.h"
#include "IDropperActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIDropperActor : public UInterface
{
	GENERATED_BODY()
};

/**
 * Indicates that the implementing actor can respond to a drop instruction
 */
class AIRENGINEERTEST_API IIDropperActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TSubclassOf<ABaseDroppable> GetDroppable();
};
