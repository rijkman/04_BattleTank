// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTurret;
class UTankBarrel; // Forward Decleration

//Hold barrel properties and elevate


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), hidecategories = ("Collision") )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector HitLocation, float LaunchSpeed);
	void SetBarrelRefference(UTankBarrel* BarrelToSet);
	void SetTurretRefference(UTurret* TurretToSet);

protected:


public:	


private:
	UTankBarrel* Barrel = nullptr;
	UTurret* Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);

	
};
