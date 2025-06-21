// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Kismet/KismetSystemLibrary.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class FIRST_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:

	UPROPERTY()
	TObjectPtr<USpringArmComponent>	mSpringArm;

	UPROPERTY()
	TObjectPtr<UCameraComponent>	mCamera;

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
