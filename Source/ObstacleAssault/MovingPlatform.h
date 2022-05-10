// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	void SetEndPoints();
	void Move(float DeltaTime);
	void Rotate(float DeltaTime);

	UPROPERTY(EditAnywhere, CATEGORY="Movement Properties") double MovingDistance = 700.0;
	UPROPERTY(EditAnywhere, CATEGORY="Movement Properties") FVector Velocity = {0, 0, -200};
	FVector EndPoints[2];
	bool EndPointIndex = 0;

	UPROPERTY(EditAnywhere, CATEGORY = "Rotation Properties") FRotator Rotation;
};
