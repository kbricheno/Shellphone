// Fill out your copyright notice in the Description page of Project Settings.


#include "Tentacle.h"

// Sets default values
ATentacle::ATentacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("TentacleRoot"));
	SetRootComponent(DefaultRoot);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TentacleMesh"));
	Mesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATentacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATentacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("tippos.y = %f"), tipPos.Y);
	//UE_LOG(LogTemp, Warning, TEXT("tippos.z = %f"), tipPos.Z);
	Mesh->SetWorldLocation(tipPos);
}

