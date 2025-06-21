// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultGameMode.h"
#include "../Player/Warrior.h"
#include "../Player/Magicion.h"

ADefaultGameMode::ADefaultGameMode()
{
	DefaultPawnClass = AWarrior::StaticClass();
}
