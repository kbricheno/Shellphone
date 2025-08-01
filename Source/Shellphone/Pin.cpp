// Fill out your copyright notice in the Description page of Project Settings.


#include "Pin.h"

// Sets default values
APin::APin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_defaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(m_defaultRoot);

	m_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PinMesh"));
	m_mesh->SetupAttachment(RootComponent);

	m_collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	m_collider->SetSphereRadius(15.f);
	m_collider->SetupAttachment(RootComponent);
}

void APin::BeginPlay()
{
	Super::BeginPlay();
	//hitbox size viewer
	//DrawDebugSphere(GetWorld(), GetActorLocation(), 12, 10, FColor::Blue, true, -1);
}

void APin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_currentTentacle)
	{
		m_currentTentacle->UpdateTentacleTipPos(GetActorLocation() + (GetActorForwardVector() * tentaclePinDepth));
	}
}

void APin::AttachTentacle(ATentacle* tentacle) 
{
	m_currentTentacle = tentacle;
	//connection achieved
}

