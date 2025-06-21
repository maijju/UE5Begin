// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PlatformGameState.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API APlatformGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	APlatformGameState();

protected:
	UPROPERTY(VisibleAnywhere)
	int32	mItemCount = 5;

public:
	virtual void BeginPlay() override;

public:
	void	DeleteItem()
	{
		--mItemCount;
	}

	int32 GetItemCount()
	{
		return mItemCount;
	}
	
};
