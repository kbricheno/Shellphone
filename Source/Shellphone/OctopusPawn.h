// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "UnrealClient.h"
#include "Tentacle.h"
#include "Pin.h"
#include "OctopusPawn.generated.h"

class UInputMappingContext;


UCLASS()
class SHELLPHONE_API AOctopusPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AOctopusPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultRoot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "EnhancedInput")
	UInputMappingContext* InputMapping;

	APlayerController* m_OctopusController;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* MoveAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* InteractAction;

	void Interact(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere)
	TArray<ATentacle*> m_allTentacles;

	UPROPERTY(EditAnywhere)
	float tentacleHoverDepth;

private:
	void LockTentacle();
	void ReleaseTentacle(ATentacle* newTentacle);

	ATentacle* m_currentTentacle = nullptr;
};
