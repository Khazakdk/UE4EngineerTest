// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveInstruction.h"
#include "Misc/CString.h"

bool UMoveInstruction::ExecuteInstruction(APawn* TargetPawn, FString Options)
{
  FVector newRobotLocation = TargetPawn->GetActorLocation();
  FVector forwardVector = TargetPawn->GetActorForwardVector();
  float distance = Options.IsEmpty() ? 100 : FCString::Atof(*Options);
  // Flip the x and y components from the forward vector so the visuals make sense
  newRobotLocation.Y += forwardVector.X * distance;
  newRobotLocation.X += forwardVector.Y * distance;

  UE_LOG(LogTemp, Display, TEXT("Attempting to execute move using forward vector %s"), *forwardVector.ToString());
  TargetPawn->SetActorLocation(newRobotLocation, true);

  return true;
}
