// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabberRobot.h"

int AGrabberRobot::DocumentCount = 1;

int AGrabberRobot::GetDocumentCount_Implementation()
{
  return AGrabberRobot::DocumentCount++;
}