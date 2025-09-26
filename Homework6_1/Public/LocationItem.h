// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LocationItem.generated.h"

UCLASS()
class HOMEWORK6_1_API ALocationItem : public AActor
{
	GENERATED_BODY()

public:
	ALocationItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Properties")
	float MaxRange;

	FVector StartLocation;

	int32 MoveDirection;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
