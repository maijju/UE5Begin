// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrier.h"

// Sets default values
ABarrier::ABarrier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mRot = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("Rot"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Sphere_center.Sphere_center'"));

	mRot->RotationRate = FRotator(0.0, 60.f, 0.0);

	if (MeshAsset.Succeeded())
		mMesh->SetStaticMesh(MeshAsset.Object);


}

// Called when the game starts or when spawned
void ABarrier::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarrier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

