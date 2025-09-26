// Fill out your copyright notice in the Description page of Project Settings.


#include "LocationItem.h"

// Sets default values
ALocationItem::ALocationItem()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	PrimaryActorTick.bCanEverTick = true;

	MoveSpeed = 200.f;
	MaxRange = 100.f;
	MoveDirection = 1;
}

void ALocationItem::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void ALocationItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		FVector CurrentLocation = GetActorLocation();

		float DeltaMove = MoveSpeed * MoveDirection * DeltaTime;

		CurrentLocation.X += DeltaMove;

		//FVector::Dist = 두 점 사이의 거리(스칼라 값)를 계산하는 정적 함수
		//StartLocation → MaxRange → StartLocation → MaxRange 순으로 왕복
		float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

		if (DistanceMoved > MaxRange) 
		{
			MoveDirection *= -1;

			float Overshoot = DistanceMoved - MaxRange;
			CurrentLocation.X += MoveDirection * Overshoot;
		}
		SetActorLocation(CurrentLocation);
	}

}

