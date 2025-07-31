// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "OctopusController.generated.h"

/**
 * 
 */
UCLASS()
class SHELLPHONE_API AOctopusController : public APlayerController
{
	GENERATED_BODY()

protected:
	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
