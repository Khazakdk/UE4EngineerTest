// Fill out your copyright notice in the Description page of Project Settings.


#include "DropInstruction.h"
#include "Kismet\KismetSystemLibrary.h"
#include "..\Robots\IDropperActor.h"

bool UDropInstruction::ExecuteInstruction(APawn* TargetPawn)
{
  if (UKismetSystemLibrary::DoesImplementInterface(TargetPawn, UIDropperActor::StaticClass()))
  {
    FVector location(TargetPawn->GetActorLocation());
    FVector forwardVector = TargetPawn->GetActorForwardVector();
    // Flip the x and y components from the forward vector so the visuals make sense
    location.Y += forwardVector.X * 100;
    location.X += forwardVector.Y * 100;
    FRotator rotation(TargetPawn->GetActorRotation());
    FActorSpawnParameters SpawnInfo;

    GetWorld()->SpawnActor<ABaseDroppable>(IIDropperActor::Execute_GetDroppable(TargetPawn), location, rotation, SpawnInfo);
    return true;
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Tried to execute drop sphere on actor that does not implement IDropperActor, skipping"));
    return false;
  }
}