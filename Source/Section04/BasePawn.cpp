// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include"Runtime/Engine/Classes/Kismet/GameplayStatics.h" 


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Tank Capsule")); 
	RootComponent = Capsule;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Body"));
	BaseMesh->SetupAttachment(Capsule);
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Body"));
	TurretMesh->SetupAttachment(BaseMesh);
	ProjectileSpawner = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Spawner"));
	ProjectileSpawner->SetupAttachment(TurretMesh);
	
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretMesh->SetWorldRotation(
			FMath::RInterpTo(
				TurretMesh->GetComponentRotation(),
				LookAtRotation,
				UGameplayStatics::GetWorldDeltaSeconds(this),
				5.f
			)
		);
}