// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

// CoreMininmal보다 EngineMinimal이 더 많은 헤더파일을 include하고 있다
#include "EngineMinimal.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Pawn.h"
// UHT : Unreal Header Tool 
// generated 헤더는 UHT가 컴파일시 자동으로 만들어준다
#include "Planet.generated.h"

UCLASS()
class FIRST_API APlanet : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlanet();

protected:
	// C++의 스마트포인터처럼 메모리관리를 UE 가비지컬렉터로 할수있게끔 해준다.
	TObjectPtr<UStaticMeshComponent>	mSun;

	// 에디터에서 보여주는 옵션 (수정은 불가능)
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent>		mSunRotation;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>	mEarth;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent>		mEarthRotation;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>	mMoon;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<URotatingMovementComponent>	mSunRotMove;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<URotatingMovementComponent>	mEarthRotMove;

	// UProjectileMovementComponent : Actor 클래스 종류들이 사용할 수 있는 이동 컴포넌트
	// URotatingMovementComponent : Actor 클래스 종류들이 사용할 수 있는 이동 컴포넌트
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<URotatingMovementComponent>	mMoonRotMove;

	// UFloatingPawnMovement : Pawn클래스 종류들만 사용할 수 있는 이동 컴포넌트
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UFloatingPawnMovement>	mMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
