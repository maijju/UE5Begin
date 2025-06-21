// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformEndPoint.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
APlatformEndPoint::APlatformEndPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mBody = CreateDefaultSubobject<UBoxComponent>(TEXT("Body"));

	SetRootComponent(mBody);

	mBody->SetCollisionProfileName(TEXT("Item"));
	// OnComponentHit : 블록이 될때 호출될 함수를 지정하는 델리게이트.
	// OnComponentBeginOverlap : 오버랩이 시작될 때 호출될 함수를 지정하는 델리게이트.
	// OnComponentEndOverlap : 오버랩이 끝날 때 호출될 함수를 지정하는 델리게이트.
	mBody->OnComponentHit.AddDynamic(this, &APlatformEndPoint::BoxHit);
	mBody->OnComponentBeginOverlap.AddDynamic(this, &APlatformEndPoint::BoxOverlap);
	mBody->OnComponentEndOverlap.AddDynamic(this, &APlatformEndPoint::BoxEndOverlap);

}

// Called when the game starts or when spawned
void APlatformEndPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformEndPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformEndPoint::BoxHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void APlatformEndPoint::BoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);

}

void APlatformEndPoint::BoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

