// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "../Input/Input.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	mCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	mSpringArm->SetupAttachment(GetMesh());
	mCamera->SetupAttachment(mSpringArm);

	GetMesh()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Player"));

	mSpringArm->SetRelativeLocation(FVector(0.0, 0.0, 160.f));
	mSpringArm->SetRelativeRotation(FRotator(-10.f, 90.f, 0.0));
	mSpringArm->TargetArmLength = 500.f;

	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->SetWalkableFloorAngle(60.f);

	// rotation constraints
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 입력 연결을 위해 PlayerController를 얻어온다.
	APlayerController* PlayerController = Cast<APlayerController>(GetController());

	// IsValid는 인자로 들어가는 객체가 유효한지 체크한다.
	if (IsValid(PlayerController))
	{
		// EnhancedInput Subsystem을 얻어온다.
		UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>
			(PlayerController->GetLocalPlayer());

		// UPlatformInput 클래스의 CDO를 얻어온다.
		// GetDefault 함수는 <> 안에 들어가는 타입의 CDO를 얻어오는 함수이다.
		// 이 함수는 const 클래스* 타입을 리턴한다.
		const UGameInput* InputCDO = GetDefault<UGameInput>();

		// subsystem에 context를 등록한다.
		Subsystem->AddMappingContext(InputCDO->mContext, 0);
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// 이 함수는 플레이어 컨트롤러에서 여기에 빙의하면서 호출해주는 함수이다.
// UInputComponent 객체는 플레이어 컨트롤러가 가지고 있는 객체이다.
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 인자로 들어온 인풋컴포넌트를 EnhancedInputCompnenet로 형변환한다.
	// EnhancedInputComponenet는 InputComponent를 상속받아 만덜여져 있고,
	// PlayerContoller는 enhacnedInputComponeent로 객체를 생성해서 InputComponent로 저장해두고있다.

	UEnhancedInputComponent* EnhancedInput =
		Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (IsValid(EnhancedInput))
	{
		const UGameInput* InputCDO = GetDefault<UGameInput>();

		// Context에 등록된 액션의 키를 눌렀을 경우 / 뗏을 경우 동작할 함수를 지정해준다.
		// ETriggerEvent는 열거형이다.
		// Triggered = 누르고 있을때. 일정 임계값을 넘어갔을 경우. (보통 ongoing보다 얘를 많이씀)
		// Started = 처음 누를때
		// Ongoing = 입력이 계속 유지되는 동안 매 프레임 발생 (누르고 있을때)
		// Canceled = 입력 도중 둥단될때. 입력이 강제로 중단되는 경우
		// Completed = 입력이 끝났을때 (뗐을 때)
		EnhancedInput->BindAction(InputCDO->mMove, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveKey);
		EnhancedInput->BindAction(InputCDO->mRotation, ETriggerEvent::Triggered, this, &APlayerCharacter::RotationKey);
		EnhancedInput->BindAction(InputCDO->mJump, ETriggerEvent::Started, this, &APlayerCharacter::JumpKey);
		EnhancedInput->BindAction(InputCDO->mAttack, ETriggerEvent::Started, this, &APlayerCharacter::AttackKey);
		EnhancedInput->BindAction(InputCDO->mSkill1, ETriggerEvent::Started, this, &APlayerCharacter::Skill1Key);
	}
}

void APlayerCharacter::MoveKey(const FInputActionValue& Value)
{
	// 인자로 들어온 값을 FVector로 만들어준다.
	// MoveKey는 x, y에 값을 넣어두었다.
	FVector Dir = Value.Get<FVector>();


	// 1번 인자에 들어간 벡터에 2번 인자에 들어간 scale 값을 곱하여 내부에 가지고 있는 벡터에 누적시켜준다.
	AddMovementInput(GetActorForwardVector(), Dir.X);
	AddMovementInput(GetActorRightVector(), Dir.Y);
}

void APlayerCharacter::RotationKey(const FInputActionValue& Value)
{
	float Angle = Value.Get<float>();
	AddControllerYawInput(Angle);
}

void APlayerCharacter::JumpKey(const FInputActionValue& Value)
{
	// CanJump함수는 현재 캐릭터가 점프가 가능한지를 판단해준다.
	if (CanJump())
		Jump();
}

void APlayerCharacter::AttackKey(const FInputActionValue& Value)
{

}

void APlayerCharacter::Skill1Key(const FInputActionValue& Value)
{

}
