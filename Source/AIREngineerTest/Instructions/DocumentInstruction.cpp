// Fill out your copyright notice in the Description page of Project Settings.

#include "DocumentInstruction.h"
#include "..\Robots\IGrabberActor.h"
#include "..\Droppables\BaseDroppable.h"

#include "Kismet\KismetSystemLibrary.h"
#include "UnrealClient.h"
#include "Misc/Paths.h"

const float MINIMUM_LAST_RENDER_TIME = .1f;
const float MAXIMUM_DISTANCE_TO_DOCUMENT = 500; // TODO: turn this into a parameter

bool UDocumentInstruction::ExecuteInstruction(APawn* TargetPawn, FString Options)
{
  if (UKismetSystemLibrary::DoesImplementInterface(TargetPawn, UIGrabberActor::StaticClass()))
  {
    TArray<AActor*> actorsOnScreen;
    ABaseDroppable* droppable = nullptr;

    for (TObjectIterator<AActor> Itr; Itr; ++Itr)
    {
      if (Itr->GetLastRenderTime() > MINIMUM_LAST_RENDER_TIME)
      {
        actorsOnScreen.Add(*Itr);
        droppable = droppable == nullptr ? Cast<ABaseDroppable>(*Itr) : droppable;
      }
    }

    if (droppable != nullptr && droppable->GetDistanceTo(TargetPawn) < MAXIMUM_DISTANCE_TO_DOCUMENT)
    {
      CreateReport(actorsOnScreen, IIGrabberActor::Execute_GetDocumentCount(TargetPawn));
      droppable->Destroy();
      return true;
    }
    UE_LOG(LogTemp, Error, TEXT("Did not find droppable in scene, skipping report"));
    return false;
  }
  UE_LOG(LogTemp, Error, TEXT("Tried to execute document instruction on actor that does not implement IGrabberActor, skipping"));
  return false;
}

void UDocumentInstruction::CreateReport(TArray<AActor*> actors, int reportNumber)
{
  FString basePath = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
  FString screenshotName = FString::Printf(TEXT("image_%d.png"), reportNumber);
  FString logPathAndName = basePath + FString::Printf(TEXT("image_%d_actors.txt"), reportNumber);

  TArray<FString> actorNames;
  for (AActor* actor : actors)
  {
    actorNames.Add(actor->GetName());
  }

  UE_LOG(LogTemp, Display, TEXT("Saved screenshot %s"), *screenshotName);
  FScreenshotRequest::RequestScreenshot(basePath + screenshotName, false, false);

  UE_LOG(LogTemp, Display, TEXT("Saved log %s"), *logPathAndName);
  FFileHelper::SaveStringArrayToFile(actorNames, *logPathAndName, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), EFileWrite::FILEWRITE_Append);
}


