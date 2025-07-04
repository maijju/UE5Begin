// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlatformPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class FIRST_API APlatformPlayerState : public APlayerState
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere)
	int32	mScore = 0;
	
public:
	void AddScore(int32 _Score)
	{
		mScore += _Score;
	}

	int32 GetScore()
	{
		return mScore;
	}
};
