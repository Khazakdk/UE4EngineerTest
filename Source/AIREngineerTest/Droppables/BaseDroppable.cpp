// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDroppable.h"

ABaseDroppable::ABaseDroppable()
{
  this->DroppableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DroppableMesh"));
  this->RootComponent = this->DroppableMesh;
}



