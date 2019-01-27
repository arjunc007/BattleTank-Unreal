// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;
	
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(float LineTraceRange, FVector LookDirection, FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXPosition = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYPosition = 0.3333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

};
