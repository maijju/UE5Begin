// Fill out your copyright notice in the Description page of Project Settings.


#include "Magicion.h"

AMagicion::AMagicion()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		MeshAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'"));

	if (MeshAsset.Succeeded())
		GetMesh()->SetSkeletalMeshAsset(MeshAsset.Object);

	GetCapsuleComponent()->SetCapsuleHalfHeight(88.f);
	GetMesh()->SetRelativeLocation(FVector(0.0, 0.0, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.0, -90.f, 0.0));
}
