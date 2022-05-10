// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	SetEndPoints();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

void AMovingPlatform::SetEndPoints()
{
	EndPoints[0] = GetActorLocation();
	FVector normal_vector = Velocity.GetSafeNormal();
	EndPoints[1] = EndPoints[0] + MovingDistance * normal_vector;
}

void AMovingPlatform::Move(float DeltaTime)
{
	auto location = GetActorLocation();
	location += Velocity * DeltaTime;

	double distance = FVector::Distance(EndPoints[EndPointIndex], location);
	if (distance > MovingDistance)
	{
		EndPointIndex = !EndPointIndex;
		Velocity = -Velocity;
		double overshoot = FVector::Distance(EndPoints[EndPointIndex], location);
		location = EndPoints[EndPointIndex] + Velocity.GetSafeNormal() * overshoot;
	}

	SetActorLocation(location);
}
