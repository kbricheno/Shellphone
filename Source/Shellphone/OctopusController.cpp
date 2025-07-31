// Fill out your copyright notice in the Description page of Project Settings.


#include "OctopusController.h"

void AOctopusController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(true);

	//controls do not work without whatever this does
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}
