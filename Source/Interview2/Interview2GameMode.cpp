// Copyright Epic Games, Inc. All Rights Reserved.

#include "Interview2GameMode.h"
#include "Interview2Character.h"
#include "UObject/ConstructorHelpers.h"

AInterview2GameMode::AInterview2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
