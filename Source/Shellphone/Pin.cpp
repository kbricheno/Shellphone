// Fill out your copyright notice in the Description page of Project Settings.


#include "Pin.h"

// Sets default values
APin::APin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	m_defaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(m_defaultRoot);

	m_collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	m_collider->SetSphereRadius(10.f);
	m_collider->SetupAttachment(RootComponent);
}

void APin::AttachTentacle(ATentacle* tentacle) 
{
	m_tentacle = tentacle;
	//connection achieved
}

