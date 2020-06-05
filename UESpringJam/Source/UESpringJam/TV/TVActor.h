// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TVActor.generated.h"

UCLASS()
class UESPRINGJAM_API ATVActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATVActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

protected:
	class USceneComponent* root;
};
