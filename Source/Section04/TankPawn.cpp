// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATankPawn::ATankPawn()
{
	CameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	CameraArm->SetupAttachment(RootComponent);
    
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraArm);
}

void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATankPawn::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATankPawn::Turn);
    
    PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &ATankPawn::Fire);
}

// Called every frame
void ATankPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if (PlayerControllerRef)
    {
        FHitResult HitResult;
        PlayerControllerRef->GetHitResultUnderCursor(
            ECollisionChannel::ECC_Visibility, 
            false, 
            HitResult);

        DrawDebugSphere(
            GetWorld(),
            HitResult.ImpactPoint,
            3.f,
            3,
            FColor::Red,
            false,
            -1.f);
        RotateTurret(HitResult.ImpactPoint);
    }

}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void ATankPawn::Move(float Value)
{
    // UE_LOG(LogTemp, Warning, TEXT("Move: %f"), Value);    
    FVector DeltaLocation = FVector::ZeroVector;
    DeltaLocation.X = Value * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalOffset(DeltaLocation, true);
}

void ATankPawn::Turn(float Value)
{
    // UE_LOG(LogTemp, Warning, TEXT("Move: %f"), Value);    
    FRotator DeltaRotator = FRotator::ZeroRotator;
    DeltaRotator.Yaw = Value * TurnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
    AddActorLocalRotation(DeltaRotator, true);

}