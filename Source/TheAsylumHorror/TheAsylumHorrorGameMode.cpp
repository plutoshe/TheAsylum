// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "TheAsylumHorrorGameMode.h"
#include "TheAsylumHorrorHUD.h"
#include "TheAsylumHorrorCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "HAL/PlatformFilemanager.h"
#include "Misc/FileHelper.h"

FString ReadFile(FString filename)
{
	//Read file ini [project]/Content/Data/ 
		//you can change with other location
	FString directory = FPaths::Combine(FPaths::GameContentDir(), "Source/Dialog");
	FString result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();
	if (file.CreateDirectory(*directory)) {
		FString myFile = directory + "/" + filename;
		FFileHelper::LoadFileToString(result, *myFile);
	}
	return result;
}
ATheAsylumHorrorGameMode::ATheAsylumHorrorGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	// use our custom HUD class
	HUDClass = ATheAsylumHorrorHUD::StaticClass();
}
