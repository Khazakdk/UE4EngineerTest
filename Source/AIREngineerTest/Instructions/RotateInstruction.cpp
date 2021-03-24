// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateInstruction.h"

bool URotateInstruction::ExecuteInstruction(APawn* TargetPawn, FString Options)
{
  FRotator newRotation = TargetPawn->GetActorRotation();
  newRotation.Yaw += 90.0f;

  UE_LOG(LogTemp, Display, TEXT("Setting actor local rotation to %s"), *newRotation.ToString());
  TargetPawn->AddActorLocalRotation(newRotation);
  return true;
}