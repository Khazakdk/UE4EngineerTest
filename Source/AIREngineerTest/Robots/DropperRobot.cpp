// Fill out your copyright notice in the Description page of Project Settings.


#include "DropperRobot.h"

TSubclassOf<ABaseDroppable> ADropperRobot::GetDroppable_Implementation()
{
  return this->Droppable;
}