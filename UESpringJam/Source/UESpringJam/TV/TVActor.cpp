// Fill out your copyright notice in the Description page of Project Settings.


#include "TVActor.h"

// Sets default values
ATVActor::ATVActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(root);
}

// Called when the game starts or when spawned
void ATVActor::BeginPlay()
{
	Super::BeginPlay();
	
}
