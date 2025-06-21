// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformGameState.h"
#include "Kismet/GameplayStatics.h"
#include "PlatformItem.h"

void APlatformGameState::BeginPlay()
{
	Super::BeginPlay();

	// 월드에 존재하는 모든 APlatformItem 찾기
	TArray<AActor*> FoundItems;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlatformItem::StaticClass(), FoundItems);

	mItemCount = FoundItems.Num();

	UE_LOG(LogTemp, Warning, TEXT("초기 아이템 수: %d"), mItemCount);
}

APlatformGameState::APlatformGameState()
{
}
