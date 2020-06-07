// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UESpringJamGameMode.generated.h"

UCLASS(minimalapi)
class AUESpringJamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUESpringJamGameMode();

	UPROPERTY(BlueprintReadWrite)
		FTransform saveLocation;

	class AUESpringJamCharacter* playerCharacter;

	UPROPERTY(BlueprintReadWrite)
		bool playerHasInhibitor = false;

	UPROPERTY(BlueprintReadWrite)
		float guardDetectionTime = 2.0f;

	UFUNCTION(BlueprintCallable)
		void ResetPlayer();
};



