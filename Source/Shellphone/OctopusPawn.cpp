// Fill out your copyright notice in the Description page of Project Settings.


#include "OctopusPawn.h"

// Sets default values
AOctopusPawn::AOctopusPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(DefaultRoot);
}

// Called when the game starts or when spawned
void AOctopusPawn::BeginPlay()
{
	Super::BeginPlay();

	m_OctopusController = GetWorld()->GetFirstPlayerController();

	currentTentacle = allTentacles[0];
}

// Called every frame
void AOctopusPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOctopusPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AOctopusPawn::Move);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AOctopusPawn::Interact);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find an Enhanced Input Component!"));
	}
}

void AOctopusPawn::Move(const FInputActionValue& Value)
{


	//UE_LOG(LogTemp, Warning, TEXT("Moving"));

	//FVector worldPos; 
	//FVector worldDir;
	//m_OctopusController->DeprojectMousePositionToWorld(worldPos, worldDir);
	//tipPos = { worldPos.Y, worldPos.Z };

	//SetActorLocation(FVector(tipDepth, tipPos.X, tipPos.Y));

	//UE_LOG(LogTemp, Warning, TEXT("Moving, x: %f"), tipPos.X);
	//UE_LOG(LogTemp, Warning, TEXT("Moving, y: %f"), tipPos.Y);
}

void AOctopusPawn::Interact(const FInputActionValue& Value) 
{
	UE_LOG(LogTemp, Warning, TEXT("Hi"));

	//if currentTentacle is not null
	// linetrace for tag pin
	// 
	//linetrace for tag button
}

