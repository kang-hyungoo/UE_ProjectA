// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectAGameMode.h"
#include "ProjectACharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectAGameMode::AProjectAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
