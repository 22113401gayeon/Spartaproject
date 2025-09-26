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
    // �Է°� �������� (Vector2D)
    FVector2D MoveInput = Value.Get<FVector2D>();


    // DeltaTime ��������
    float DeltaTime = GetWorld()->GetDeltaSeconds();

    // �̵� �ӵ�
    float Speed = MoveSpeed; // MoveSpeed�� Ŭ���� ��� ����, EditAnywhere�� ���� ����

    // Forward / Right ���� (Z�� ����)
    FVector Forward = GetActorForwardVector(); // world ��ǥ�� return..
    Forward.Z = 0.f;
    Forward.Normalize();

    FVector Right = GetActorRightVector();
    Right.Z = 0.f;
    Right.Normalize();

    // ���� �̵� �Ÿ� ���  Right * MoveInput.Y
    FVector DeltaLocation= (Forward * MoveInput.X + Right * MoveInput.Y) * Speed * DeltaTime;


    // ���� �̵�
    AddActorWorldOffset(DeltaLocation,true);
  
}

void AMyPawn::Look(const FInputActionValue& Value)
{
    FVector2D LookInput = Value.Get<FVector2D>();
    if (LookInput.IsNearlyZero()) return;

    FRotator CurrentRotation = Controller->GetControlRotation();
    // ȸ�� �ӵ� ����
    float RotationSpeed = 1.0f;

    // Yaw �Է� ó�� (�¿� ȸ��)
    float YawInput = LookInput.X * RotationSpeed;
    CurrentRotation.Yaw += YawInput;

    // Pitch �Է� ó�� (���� ȸ��)
    float PitchInput = LookInput.Y * RotationSpeed;
    CurrentRotation.Pitch += -PitchInput;

    // Pitch ȸ���� ���� ����
    CurrentRotation.Pitch = FMath::ClampAngle(CurrentRotation.Pitch, -90.0f, 90.0f);

    // ��Ʈ�ѷ��� ȸ�� ���� ������Ʈ
    Controller->SetControlRotation(CurrentRotation);
    SetActorRotation(CurrentRotation);

}
