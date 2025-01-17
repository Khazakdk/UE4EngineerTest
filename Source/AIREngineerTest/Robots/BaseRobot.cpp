// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRobot.h"
#include "Math/UnrealMathUtility.h"

ABaseRobot::ABaseRobot()
{
  this->MovementRate = 100.0;
  this->RobotMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("RobotMesh"));
  this->RootComponent = this->RobotMesh;
}

void ABaseRobot::BeginPlay()
{
  this->RunInstructions();
}

void ABaseRobot::WalkForward()
{
  FVector robotLocation = this->GetActorLocation();
  FVector forwardVector = this->GetActorForwardVector();
  robotLocation.X += (forwardVector.X * 100);
  robotLocation.Y += (forwardVector.Y * 100);

  this->SetActorLocation(robotLocation);
}

void ABaseRobot::RunInstructions()
{  
  if (this->Instructions.IsValidIndex(0))
  {
    URobotInstruction* newInstruction = NewObject<URobotInstruction>(this, Instructions[0].Instruction);
    if (newInstruction->ExecuteInstruction(this, Instructions[0].Options))
    {
      FTimerHandle handle;
      GetWorld()->GetTimerManager().SetTimer(handle, [this]() 
        {
          this->Instructions.RemoveAt(0);
          this->RunInstructions();
        }, 
        2.0f, false);
    }
    else
      UE_LOG(LogTemp, Error, TEXT("Instruction reported failure, canceling rest of the run"));
  }
  UE_LOG(LogTemp, Display, TEXT("Instruction queue empty"));
}