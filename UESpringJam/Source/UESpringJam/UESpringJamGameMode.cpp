// Copyright Epic Games, Inc. All Rights Reserved.

#include "UESpringJamGameMode.h"
#include "UESpringJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUESpringJamGameMode::AUESpringJamGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
