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
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATentacle::StaticClass(), foundActors);

	for (int i = 0; i < foundActors.Num(); i++)
	{
		ATentacle* tentacle = Cast<ATentacle>(foundActors[i]);
		m_allTentacles.Add(tentacle);
	}
	m_currentTentacle = m_allTentacles[0];
}

// Called every frame
void AOctopusPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_currentTentacle)
	{
		FVector mouseToWorldPos, mouseToWorldDir;
		float mousePosX, mousePosY;
		m_OctopusController->GetMousePosition(mousePosX, mousePosY);
		m_OctopusController->DeprojectScreenPositionToWorld(mousePosX, mousePosY, mouseToWorldPos, mouseToWorldDir);

		m_currentTentacle->UpdateTentacleTipPos(mouseToWorldPos + (mouseToWorldDir * tentacleHoverDepth));

		//write debug line to screen
		//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0.01f, FColor::Magenta, FString::Printf(TEXT("Current tenticle: %s"), *m_currentTentacle->GetName()));
	}
}

// Called to bind functionality to input
void AOctopusPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AOctopusPawn::Interact);
		UE_LOG(LogTemp, Warning, TEXT("Input setup successful."));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find an Enhanced Input Component!"));
	}
}

void AOctopusPawn::Interact(const FInputActionValue& Value) 
{
	FHitResult hit;
	FCollisionQueryParams params;
	params.AddIgnoredActor(m_currentTentacle);
	FVector mouseToWorldPos;
	FVector mouseToWorldDir;
	m_OctopusController->DeprojectMousePositionToWorld(mouseToWorldPos, mouseToWorldDir);
	
	if (GetWorld()->LineTraceSingleByChannel(hit, mouseToWorldPos, (mouseToWorldDir * 1000) + mouseToWorldPos, ECC_Visibility, params))
	{
		//debug sphere to show hit point
		//if (hit.bBlockingHit) DrawDebugSphere(GetWorld(), hit.ImpactPoint, 5, 6, FColor::Green, true, 1);
		
		if (m_currentTentacle) 
		{
			if (APin* pin = Cast<APin>(hit.GetActor())) 
			{
				if (pin->GetTentacle() == nullptr) 
				{
					pin->AttachTentacle(m_currentTentacle);
					LockTentacle();
				}
			}		
			//else if cast to button, set button clicked
		}
		else 
		{
			if (APin* pin = Cast<APin>(hit.GetActor()))
			{
				if (ATentacle* pinTentacle = pin->GetTentacle()) 
				{
					pin->RemoveTentacle();
					ReleaseTentacle(pinTentacle);
				}
			}
		}
	}
	//if currentTentacle is not null
	// linetrace for tag pin
	// attach currentTentacle to pin; set tentacle isInUse; set pin tentacle reference; set currentTentacle to next one in array if possible
	//linetrace for tag button
	// set button clicked

	//if currentTentacle is null
	//linetrace for tag pin
	//if pin has tentacle reference
	//set currentTentacle to tentacle reference; unset tentacle isInUse; 
}

void AOctopusPawn::LockTentacle() 
{
	m_currentTentacle->SetIsFree(false);

	m_currentTentacle = nullptr;
	for (int i = 0; i < m_allTentacles.Num(); i++)
	{
		if (m_allTentacles[i]->CheckIsFree())
		{
			m_currentTentacle = m_allTentacles[i];
			break;
		}
	}
}

void AOctopusPawn::ReleaseTentacle(ATentacle* newTentacle)
{
	newTentacle->SetIsFree(true);
	m_currentTentacle = newTentacle;
}

