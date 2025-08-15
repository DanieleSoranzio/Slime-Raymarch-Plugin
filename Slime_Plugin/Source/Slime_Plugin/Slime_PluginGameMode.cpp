// Copyright Epic Games, Inc. All Rights Reserved.

#include "Slime_PluginGameMode.h"
#include "Slime_PluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASlime_PluginGameMode::ASlime_PluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
