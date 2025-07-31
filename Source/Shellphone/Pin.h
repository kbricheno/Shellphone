// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tentacle.h"
#include "Components/SphereComponent.h"
#include "Pin.generated.h"

UCLASS()
class SHELLPHONE_API APin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APin();

public:	

	void AttachTentacle(ATentacle* tentacle);

	USceneComponent* m_defaultRoot;

	ATentacle* m_tentacle = nullptr;

	UPROPERTY(EditAnywhere)
	USphereComponent* m_collider;

};
