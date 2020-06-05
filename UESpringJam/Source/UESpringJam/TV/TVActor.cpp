// Fill out your copyright notice in the Description page of Project Settings.


#include "TVActor.h"
#include "..\UESpringJamCharacter.h"

// Sets default values
ATVActor::ATVActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(root);
	root->bEditableWhenInherited = true;
	root->SetMobility(EComponentMobility::Static);

	tvmodel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TVModel"));
	tvmodel->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);
	tvmodel->bEditableWhenInherited = true;
	tvmodel->SetMobility(EComponentMobility::Static);
	screenmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ScreenMesh"));
	screenmesh->AttachToComponent(tvmodel, FAttachmentTransformRules::KeepRelativeTransform);
	screenmesh->bEditableWhenInherited = true;
	screenmesh->SetMobility(EComponentMobility::Static);
	destination = CreateDefaultSubobject<USceneComponent>(TEXT("Destination"));
	destination->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);
	destination->bEditableWhenInherited = true;
	destination->SetMobility(EComponentMobility::Static);
}

// Called when the game starts or when spawned
void ATVActor::BeginPlay()
{
	Super::BeginPlay();
	
	signalFloat1 = FMath::RandRange(0.0f, 1.0f);
	signalFloat1Goal = FMath::RandRange(0.0f, 1.0f);
	signalFloat2 = FMath::RandRange(0.0f, 9.0f);
	signalFloat2Goal = FMath::RandRange(0.0f, 9.0f);
	UpdateSignal();
}

void ATVActor::Interact(AActor* interactor)
{
	if (CheckCanTeleport())
	{
		Teleport(interactor);
	}
	else
	{
		StartMinigame(interactor);
	}

}

bool ATVActor::CheckCanTeleport()
{
	return signalStength >= 0.95f;
}

void ATVActor::Teleport(AActor* interactor)
{
	interactor->SetActorLocation(destination->GetComponentTransform().GetLocation());
}


void ATVActor::SetSignalOne(float input) 
{
	signalFloat1 = input; 
	UpdateSignal();
}

void ATVActor::SetSignalTwo(float input)
{
	signalFloat2 = input; 
	UpdateSignal();
}

void ATVActor::UpdateSignal()
{
	float signal1 = abs(signalFloat1 - signalFloat1Goal) * 0.5f;
	float signal2 = abs(signalFloat2 - signalFloat2Goal) / 9.0f * 0.5f;
	signalStength = 1 - signal1 - signal2;
}