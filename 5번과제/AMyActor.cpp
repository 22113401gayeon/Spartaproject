    // Fill out your copyright notice in the Description page of Project Settings.


#include "AMyActor.h"
#include "Math/UnrealMathUtility.h" 
#include "Engine/Engine.h"  

// Sets default values
AAMyActor::AAMyActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

}

int32 Step()
{
    return FMath::RandRange(0, 1);
}

void move()
{
    FVector2D CurrentPos(0, 0);


    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
		UE_LOG(LogTemp, Warning, TEXT("Move 0: X = %d, Y = %d"), static_cast<int>(CurrentPos.X), static_cast<int>(CurrentPos.Y));
        }
        else {
            int32 stepX = Step();
            int32 stepY = Step();

            CurrentPos.X += stepX;
            CurrentPos.Y += stepY;

            UE_LOG(LogTemp, Warning, TEXT("Move %d: X = %d, Y = %d"), i+1, static_cast<int>(CurrentPos.X), static_cast<int>(CurrentPos.Y));
        }
    }

}

// Called when the game starts or when spawned
void AAMyActor::BeginPlay()
{
    Super::BeginPlay();

    FMath::RandInit(FDateTime::Now().GetMillisecond());

    move();
}

// Called every frame
void AAMyActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}
