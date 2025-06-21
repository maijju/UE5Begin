// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerDefaultAniminstance.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API UPlayerDefaultAniminstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float mMoveSpeed = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float mJumpSpeed = 0.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool mIsMidAir = false;

public:
	void NativeBeginPlay();
	void NativeInitializeAnimation();

	// 게임 스레드에서 호출
	void NativeUpdateAnimation(float DeltaSeconds);

	// 애니메이션 스레드에서 호출
	void NativeThreadSafeUpdateAnimation(float DeltaSeconds);
	void NativePostEvaluateAnimation();
	void NativeUninitializeAnimation();
};
