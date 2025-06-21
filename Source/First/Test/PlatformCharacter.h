// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Character.h"
#include "PlatformCharacter.generated.h"

UCLASS()
class FIRST_API APlatformCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlatformCharacter();

protected:

	UPROPERTY()
	TObjectPtr<USpringArmComponent>	mSpringArm;

	UPROPERTY()
	TObjectPtr<UCameraComponent>	mCamera;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>	mBarrierMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<URotatingMovementComponent>	mBarrierRot;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 인자는 고정
	void MoveKey(const FInputActionValue& Value);
	void RotationKey(const FInputActionValue& Value);
	void JumpKey(const FInputActionValue& Value);
	void AttackKey(const FInputActionValue& Value);
	void Skill1Key(const FInputActionValue& Value);
};
