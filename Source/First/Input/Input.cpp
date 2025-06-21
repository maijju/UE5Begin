// Fill out your copyright notice in the Description page of Project Settings.


#include "Input.h"

UPlatformInput::UPlatformInput()
{
	static ConstructorHelpers::FObjectFinder<UInputMappingContext>
		InputContext(TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMCPlatform.IMCPlatform'"));

	mContext = InputContext.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>
		MoveAction(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IAMove.IAMove'"));

	mMove = MoveAction.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>
		RotationAction(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IARotation.IARotation'"));

	mRotation = RotationAction.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>
		JumpAction(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IAJump.IAJump'"));

	mJump = JumpAction.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>
		AttackAction(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IAAttack.IAAttack'"));

	mAttack = AttackAction.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction>
		Skill1Action(TEXT("/Script/EnhancedInput.InputAction'/Game/Input/IASkill1.IASkill1'"));

	mSkill1 = Skill1Action.Object;
}