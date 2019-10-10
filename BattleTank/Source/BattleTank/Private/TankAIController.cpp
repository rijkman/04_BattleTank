// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	GetControlledTank()->AimAt(GetControlledTank()->GetActorLocation());
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerController = GetPlayerTank();
	if (PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Found: %s"), *(PlayerController->GetName()))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find PlayerController"));
	}
}

ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
	{
		return Cast<ATank>(PlayerPawn);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Cannot find PlayerController"));
		return 0;
	}
}




