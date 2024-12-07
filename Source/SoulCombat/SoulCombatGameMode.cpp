// Copyright Epic Games, Inc. All Rights Reserved.

#include "SoulCombatGameMode.h"
#include "SoulCombatCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASoulCombatGameMode::ASoulCombatGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
