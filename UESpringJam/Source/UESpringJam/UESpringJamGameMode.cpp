// Copyright Epic Games, Inc. All Rights Reserved.

#include "UESpringJamGameMode.h"
#include "UESpringJamHUD.h"
#include "UESpringJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUESpringJamGameMode::AUESpringJamGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUESpringJamHUD::StaticClass();
}
