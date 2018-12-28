// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TheAsylumHorrorGameMode.h"
#include "TheAsylumHorrorHUD.h"
#include "TheAsylumHorrorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATheAsylumHorrorGameMode::ATheAsylumHorrorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATheAsylumHorrorHUD::StaticClass();
}
