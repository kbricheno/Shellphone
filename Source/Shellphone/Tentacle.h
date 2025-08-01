// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Tentacle.generated.h"

UCLASS()
class SHELLPHONE_API ATentacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATentacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultRoot;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	FVector rootPos = { 0.f, 0.f, 0.f };

	void UpdateTentacleTipPos(FVector newPos) { tipPos = newPos; }

	bool CheckIsFree() const { return isFree; }
	void SetIsFree(bool free) { isFree = free; }

private:
	bool isFree = true;
	FVector tipPos;
};
