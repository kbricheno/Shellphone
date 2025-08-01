// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tentacle.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Pin.generated.h"

UCLASS()
class SHELLPHONE_API APin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APin();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	ATentacle* GetTentacle() const { return m_currentTentacle; }
	void RemoveTentacle() { m_currentTentacle = nullptr; }
	void AttachTentacle(ATentacle* tentacle);

	USceneComponent* m_defaultRoot;

	ATentacle* m_currentTentacle = nullptr;

	UPROPERTY(EditAnywhere)
	USphereComponent* m_collider;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* m_mesh;

	UPROPERTY(EditAnywhere)
	float tentaclePinDepth;

};
