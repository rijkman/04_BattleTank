// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"

void UTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * RotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto RawRotation = RotationChange + RelativeRotation.Yaw;
	SetRelativeRotation(FRotator(0, RawRotation, 0));
}



