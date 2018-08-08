// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform() {
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority()) {
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GoBack = false;
	StartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	DistanceToTarget = FVector::Dist(StartLocation, GlobalTargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (ActiveTriggers > 0) {
		MovePlatform(DeltaTime);
	}
	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	if (HasAuthority()) {
		if (ReturnToStart) {

			FVector CurrentLocation = GetActorLocation();
			GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
			FVector Direction = (GlobalTargetLocation - CurrentLocation).GetSafeNormal();

			if (!GoBack) {
				CurrentLocation += Speed * DeltaTime * Direction;
			}
			else {
				CurrentLocation -= Speed * DeltaTime * Direction;
			}

			SetActorLocation(CurrentLocation);

			if (DistanceToTarget < FVector::Dist(StartLocation, CurrentLocation)) {
				StartLocation = CurrentLocation;
				GoBack = !GoBack;
			}

		}
		else {
			FVector CurrentLocation = GetActorLocation();
			FVector GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
			FVector Direction = (GlobalTargetLocation - CurrentLocation).GetSafeNormal();
			//CurrentLocation += FVector(Speed * DeltaTime, 0, 0);
			CurrentLocation += Speed * DeltaTime * Direction;
			SetActorLocation(CurrentLocation);
		}
	}
}

void AMovingPlatform::AddActiveTrigger()
{
	ActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	if (ActiveTriggers > 0) ActiveTriggers--;
}

