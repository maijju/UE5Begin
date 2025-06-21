// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformBullet.h"

// Sets default values
APlatformBullet::APlatformBullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mBody = CreateDefaultSubobject<USphereComponent>(TEXT("Body"));
	mMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));

	SetRootComponent(mBody);

	mMesh->SetupAttachment(mBody);

	// 업데이트 대상을 루트로 지정. 루트가 슝 날라간다
	mMovement->SetUpdatedComponent(RootComponent);


	// 델리게이트: 함수 포인터를 등록해놓고 필요할때 호출함
	mMovement->InitialSpeed = 2000.f;
	mMovement->ProjectileGravityScale = .5f;
	mMovement->OnProjectileStop.AddDynamic(this, &APlatformBullet::ProjectileStop);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Sphere_center.Sphere_center'"));

	if (MeshAsset.Succeeded())
		mMesh->SetStaticMesh(MeshAsset.Object);

	mMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	mBody->SetSphereRadius(25.f);
	mBody->SetCollisionProfileName(TEXT("BlockAll"));
}

// Called when the game starts or when spawned
void APlatformBullet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformBullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*
언리얼 충돌 시스템
Ignore, Overlap, Blcok 3가지 충돌 상태가 있다.
Ignore: 충돌을 무시한다.
Overlap: 충돌은 하지만 겹쳐지는것을 허용한다.
Block: 충돌을하며 충돌하는 순간 겹쳐지지 않게 밀어낸다.
충돌하는 A , B 가 있을 때 둘중에 하나라도 Ignore가 있으면 Ignore가 우선
둘중에 하나가 Overlap이면 Block 안됨
둘다 Block이어야 Block됨
*/
void APlatformBullet::ProjectileStop(const FHitResult& Hit)
{
	Destroy();
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("Hit"));
}

