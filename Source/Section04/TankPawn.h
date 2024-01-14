// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "TankPawn.generated.h"

/**
 * 
 */
UCLASS()
class SECTION04_API ATankPawn : public ABasePawn
{
	GENERATED_BODY()
public:
	ATankPawn();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category="Camera");
	class USpringArmComponent* CameraArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category="Camera");
	class UCameraComponent* Camera;

	void Move(float Value);
	void Turn(float Value);
	
};
