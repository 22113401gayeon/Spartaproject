// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "MyPlayerController.h"
#include "EnhancedInputComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AMyPawn::AMyPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComp"));
    RootComponent = CapsuleComp;
    CapsuleComp->SetCollisionProfileName(TEXT("Pawn"));
    CapsuleComp->SetSimulatePhysics(false);


    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArmComp->SetupAttachment(RootComponent);
    SpringArmComp->bUsePawnControlRotation = true;


    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
    CameraComp->bUsePawnControlRotation = false;

    MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
    MeshComp->SetupAttachment(RootComponent);
    MeshComp->SetSimulatePhysics(false);



}

void AMyPawn::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
    {   
        if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
        {
            if (AMyPlayerController* PlayerController = Cast<AMyPlayerController>(GetController()))
            {
                if (MoveAction)
                {
                    EnhancedInput->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyPawn::Move);
                }
                if (LookAction)
                {
                    EnhancedInput->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyPawn::Look);
                }
            }
        }
	}

void AMyPawn::Move(const FInputActionValue& Value)
{
    // 입력값 가져오기 (Vector2D)
    FVector2D MoveInput = Value.Get<FVector2D>();


    // DeltaTime 가져오기
    float DeltaTime = GetWorld()->GetDeltaSeconds();

    // 이동 속도
    float Speed = MoveSpeed; // MoveSpeed는 클래스 멤버 변수, EditAnywhere로 세팅 가능

    // Forward / Right 벡터 (Z축 제거)
    FVector Forward = GetActorForwardVector(); // world 좌표계 return..
    Forward.Z = 0.f;
    Forward.Normalize();

    FVector Right = GetActorRightVector();
    Right.Z = 0.f;
    Right.Normalize();

    // 최종 이동 거리 계산  Right * MoveInput.Y
    FVector DeltaLocation= (Forward * MoveInput.X + Right * MoveInput.Y) * Speed * DeltaTime;


    // 실제 이동
    AddActorWorldOffset(DeltaLocation,true);
  
}

void AMyPawn::Look(const FInputActionValue& Value)
{
    FVector2D LookInput = Value.Get<FVector2D>();
    if (LookInput.IsNearlyZero()) return;

    FRotator CurrentRotation = Controller->GetControlRotation();
    // 회전 속도 조절
    float RotationSpeed = 1.0f;

    // Yaw 입력 처리 (좌우 회전)
    float YawInput = LookInput.X * RotationSpeed;
    CurrentRotation.Yaw += YawInput;

    // Pitch 입력 처리 (상하 회전)
    float PitchInput = LookInput.Y * RotationSpeed;
    CurrentRotation.Pitch += -PitchInput;

    // Pitch 회전을 범위 제한
    CurrentRotation.Pitch = FMath::ClampAngle(CurrentRotation.Pitch, -90.0f, 90.0f);

    // 컨트롤러의 회전 값을 업데이트
    Controller->SetControlRotation(CurrentRotation);
    SetActorRotation(CurrentRotation);

}
