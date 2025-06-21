// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "UObject/NoExportTypes.h"
#include "Input.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API UPlatformInput : public UObject
{
	GENERATED_BODY()
	
public:
	UPlatformInput();

public:
	TObjectPtr<UInputMappingContext> mContext;
	TObjectPtr<UInputAction>		mMove;
	TObjectPtr<UInputAction>		mRotation;
	TObjectPtr<UInputAction>		mJump;
	TObjectPtr<UInputAction>		mAttack;
	TObjectPtr<UInputAction>		mSkill1;
};

UCLASS()
class FIRST_API UGameInput : public UObject
{
	GENERATED_BODY()

public:
	UGameInput();

public:
	TObjectPtr<UInputMappingContext> mContext;
	TObjectPtr<UInputAction>		mMove;
	TObjectPtr<UInputAction>		mRotation;
	TObjectPtr<UInputAction>		mJump;
	TObjectPtr<UInputAction>		mAttack;
	TObjectPtr<UInputAction>		mSkill1;
};

