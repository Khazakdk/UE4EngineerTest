// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveInstruction.h"

bool UMoveInstruction::ExecuteInstruction(APawn* TargetPawn)
{
  FVector newRobotLocation = TargetPawn->GetActorLocation();
  FVector forwardVector = TargetPawn->GetActorForwardVector();
  // Flip the x and y components from the forward vector so the visuals make sense
  newRobotLocation.Y += forwardVector.X * 100;
  newRobotLocation.X += forwardVector.Y * 100;

  UE_LOG(LogTemp, Display, TEXT("Attempting to execute move using forward vector %s"), *forwardVector.ToString());
  TargetPawn->SetActorLocation(newRobotLocation, true);

  return true;
}
