// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto ppawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!ppawn)
	{
		return nullptr;
	}
	return Cast<ATank>(ppawn);
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		//TODO Move towards player
		//Start aiming at player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		//Fire if ready
	}
}