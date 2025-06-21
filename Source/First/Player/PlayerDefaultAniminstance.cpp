// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDefaultAniminstance.h"
#include "PlayerCharacter.h"

void UPlayerDefaultAniminstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UPlayerDefaultAniminstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
}

void UPlayerDefaultAniminstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	// 이 애님인스턴스를 가지고 있는 스켈레탈 메시 컴포넌트가 속해있는 Pawn을 얻어온다.
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(TryGetPawnOwner());

	if (IsValid(PlayerCharacter))
	{
		UCharacterMovementComponent* Movement =
			PlayerCharacter->GetCharacterMovement();

		if (Movement)
		{
			mMoveSpeed = abs(Movement->Velocity.X + Movement->Velocity.Y);
			mJumpSpeed = Movement->Velocity.Z;
			mIsMidAir = Movement->IsFalling();
		}
	}
}

void UPlayerDefaultAniminstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

}

void UPlayerDefaultAniminstance::NativePostEvaluateAnimation()
{
	Super::NativePostEvaluateAnimation();
}

void UPlayerDefaultAniminstance::NativeUninitializeAnimation()
{
	Super::NativeUninitializeAnimation();
}
