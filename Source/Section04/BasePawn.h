// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class SECTION04_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Pawn Property");
	int32 Live = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Property");
	float Speed = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Property");
	float TurnSpeed = 45.0f;

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category="Components");
	class UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category="Components");
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category="Components");
	UStaticMeshComponent* TurretMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category="Components");
	USceneComponent* ProjectileSpawner;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;
};
