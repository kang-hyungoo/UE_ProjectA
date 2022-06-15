// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectAGameMode.h"
#include "ProjectACharacter.h"
#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"

AProjectAGameMode::AProjectAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FObjectFinder<UDataTable> DataTable(TEXT("/Game/Data/DT_CharacterData"));
	if (DataTable.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("DataTable Succeed!"));
		CharacterDataTable = DataTable.Object;
	}
}


UDataTable* AProjectAGameMode::GetCharacterDataTable()
{
	return CharacterDataTable;
}