// Fill out your copyright notice in the Description page of Project Settings.


#include "Warrior.h"

AWarrior::AWarrior()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		MeshAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonKwang/Characters/Heroes/Kwang/Meshes/KwangAlbino.KwangAlbino'"));

	if (MeshAsset.Succeeded())
		GetMesh()->SetSkeletalMeshAsset(MeshAsset.Object);

	GetCapsuleComponent()->SetCapsuleHalfHeight(94.f);
	GetMesh()->SetRelativeLocation(FVector(0.0, 0.0, -94.f));
	GetMesh()->SetRelativeRotation(FRotator(0.0, -90.f, 0.0));

	// 클래스 정보를 읽어올 경우 경로의 가장 끝에 _C를 무조건 붙여야한다.
	static ConstructorHelpers::FClassFinder<UAnimInstance>
		AnimAsset(TEXT("/Script/Engine.AnimBlueprint'/Game/Player/ABPTest.ABPTest_C'"));

	if (AnimAsset.Succeeded())
		GetMesh()->SetAnimInstanceClass(AnimAsset.Class);
}
