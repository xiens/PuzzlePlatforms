// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.h"


// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PressureVolume = CreateDefaultSubobject<UBoxComponent>(FName("PressureVolume"));
	if (!ensure(PressureVolume != nullptr)) return;
	RootComponent = PressureVolume;

	
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
	PressureVolume->bGenerateOverlapEvents = true;
	PressureVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapBegin);
	PressureVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnOverlapEnd);
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformTrigger::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//UE_LOG(LogTemp, Warning, TEXT("start moving platform"))
		//if (PlatformsToTrigger.Num() != 0) {
			UE_LOG(LogTemp, Warning, TEXT("start moving platform"))
			for (AMovingPlatform* Platform : PlatformsToTrigger)
			{
				Platform->AddActiveTrigger();
			}

	//}
}

void APlatformTrigger::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//UE_LOG(LogTemp, Warning, TEXT("stop moving platform"))
		//if (PlatformsToTrigger.Num() != 0) {
			for (AMovingPlatform* Platform : PlatformsToTrigger)
			{
				Platform->RemoveActiveTrigger();
			}

		//}
}

