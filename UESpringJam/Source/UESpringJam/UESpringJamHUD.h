// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UESpringJamHUD.generated.h"

UCLASS()
class AUESpringJamHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUESpringJamHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

