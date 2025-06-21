// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformItem.h"
#include "PlatformGameState.h"
#include "PlatformPlayerState.h"

// Sets default values
APlatformItem::APlatformItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mBody = CreateDefaultSubobject<UBoxComponent>(TEXT("Body"));
	mMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SetRootComponent(mBody);
	mMesh->SetupAttachment(mBody);

	mBody->SetBoxExtent(FVector(50.0, 50.0, 50.0));
	mMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	mBody->SetCollisionProfileName(TEXT("Item"));

	// OnComponentHit : 블록이 될때 호출될 함수를 지정하는 델리게이트.
	// OnComponentBeginOverlap : 오버랩이 시작될 때 호출될 함수를 지정하는 델리게이트.
	// OnComponentEndOverlap : 오버랩이 끝날 때 호출될 함수를 지정하는 델리게이트.
	mBody->OnComponentHit.AddDynamic(this, &APlatformItem::BoxHit);
	mBody->OnComponentBeginOverlap.AddDynamic(this, &APlatformItem::BoxOverlap);
	mBody->OnComponentEndOverlap.AddDynamic(this, &APlatformItem::BoxEndOverlap);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube_Center.Shape_Cube_Center'"));

	if (MeshAsset.Succeeded())
		mMesh->SetStaticMesh(MeshAsset.Object);
}

// Called when the game starts or when spawned
void APlatformItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatformItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformItem::BoxHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
}

void APlatformItem::BoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlatformGameState* GameState = GetWorld()->GetGameState<APlatformGameState>();

	if (GameState)
	{
		GameState->DeleteItem();
	}

	APlayerController* Control = GetWorld()->GetFirstPlayerController();

	if (Control)
	{
		APlatformPlayerState* State = Control->GetPlayerState<APlatformPlayerState>();

		if (State)
			State->AddScore(mScore);

		FString Message = TEXT("남은 아이템 수: ") + FString::FromInt(GameState->GetItemCount()) +
			TEXT("\n현재 점수: ") + FString::FromInt(State->GetScore());

		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Green,
			Message
		);

		Destroy();

	}
}

void APlatformItem::BoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

