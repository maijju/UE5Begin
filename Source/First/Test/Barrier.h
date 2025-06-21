// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Barrier.generated.h"

UCLASS()
class FIRST_API ABarrier : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrier();

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>	mMesh;
	TObjectPtr<URotatingMovementComponent>	mRot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
