// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDroppable.generated.h"

UCLASS()
class AIRENGINEERTEST_API ABaseDroppable : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseDroppable();

public:	

  UPROPERTY(BlueprintReadWrite, EditAnywhere)
  UStaticMeshComponent* DroppableMesh;

};
