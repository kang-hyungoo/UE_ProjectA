// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectAGameMode.generated.h"

class UDataTable;

UCLASS(minimalapi)
class AProjectAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProjectAGameMode();

	UDataTable* GetCharacterDataTable();

private:
	UDataTable* CharacterDataTable;
};



