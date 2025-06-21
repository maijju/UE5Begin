// Fill out your copyright notice in the Description page of Project Settings.


#include "Planet.h"

// Sets default values
/*
언리얼 C++클래스는 Actor의 경우 에디터에 배치하는 순간 생성자가 호출이 된다.
플레이를 누른다고 호출되는 것이 아님!! (BeginPlay가 있는 이유)

CDO(Class Default Object):
언리얼 Editor나 빌드된 게임을 실행한 후에 모든 UCLASS들의 생성자를 각각 호출해서 UCLASS마다 1개씩 기본으로 생성되는 기본 인스턴스이다.

*/
APlanet::APlanet()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// 이게 true여야 tick이 콜 된다.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트를 생성한다.
	// TEXT매크로를 쓰는 이유는 언리얼은 텍스트를 다 유니코드로 인코딩하기 때문이다.
	mSun = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sun"));
	mSunRotation = CreateDefaultSubobject<USceneComponent>(TEXT("SunRotation"));
	mEarth = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Earth"));
	mEarthRotation = CreateDefaultSubobject<USceneComponent>(TEXT("EarthRotation"));
	mMoon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Moon"));

	mSunRotMove = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("SunRotMove"));
	mEarthRotMove = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("EarthRotMove"));
	mMoonRotMove = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MoonRotMove"));

	mMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	// 루트 컴포넌트를 지정한다.
	SetRootComponent(mSun);

	// SunRotation을 Sun의 자식컴포넌트로 지정한다.
	mSunRotation->SetupAttachment(mSun);
	mEarth->SetupAttachment(mSunRotation);
	mEarthRotation->SetupAttachment(mSunRotation);
	mMoon->SetupAttachment(mEarthRotation);

	// RotatingMovementComponent가 회전시켜줄 대상 Componenet를 지정한다.
	mSunRotMove->SetUpdatedComponent(mSunRotation);
	mEarthRotMove->SetUpdatedComponent(mEarth);
	mMoonRotMove->SetUpdatedComponent(mEarthRotation);

	// Root 컴포넌트를 이동시켜서 하위 컴포너느 모두 이동되게한다.
	mMovement->SetUpdatedComponent(mSun);

	// Pitch : Y축회전
	// yaw : z츅회전
	// Roll : x축회전
	mSunRotMove->RotationRate = FRotator(0.0, 60.f, 0.0);
	mEarthRotMove->RotationRate = FRotator(0.0, 100.f, 0.0);
	mMoonRotMove->RotationRate = FRotator(0.0, 130.f, 0.0);

	// ConstrcutorHelpers에서 제공하는 에셋 로딩 기능은 오로지 클래스 생성자에서만 사용이 가능하다.
	// 템플릿 타입에는 로딩하고자 하는 에셋 타입을 지정한다.
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (MeshAsset.Succeeded())
	{
		// MeshAsset.Object : 로딩된 메쉬가 들어가있는 변수
		mSun->SetStaticMesh(MeshAsset.Object);
		mEarth->SetStaticMesh(MeshAsset.Object);
		mMoon->SetStaticMesh(MeshAsset.Object);
	}

	mEarth->SetRelativeLocation(FVector(380.f, 0.0, 0.0));
	mEarthRotation->SetRelativeLocation(FVector(380.f, 0.0, 0.0));

	mMoon->SetRelativeLocation(FVector(110.f, 0.0, 0.0));

	mEarth->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	mMoon->SetRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));

	// 어짜피 똑같은 메쉬를 계속 쓸거기때문에 정적변수로 메쉬를 가져온다. 이럴 경우 로딩 자체를 한번밖에 안한다.
}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
	// Super : 부모클래스
	// 여기서 Super는 Pawn 클래스가 된다.
	Super::BeginPlay();
	
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 벡터의 앞쪽 방향을 가져옴
	mMovement->AddInputVector(GetActorForwardVector());
}

// Called to bind functionality to input
void APlanet::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}