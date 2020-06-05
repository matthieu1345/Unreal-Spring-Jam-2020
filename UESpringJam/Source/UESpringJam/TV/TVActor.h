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
	UFUNCTION(BlueprintCallable)
		void Interact(AActor* interactor);

	UFUNCTION(BlueprintCallable)
		void SetSignalOne(float input);
	UFUNCTION(BlueprintCallable)
		void SetSignalTwo(float input);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void UpdateSignal();
	bool CheckCanTeleport();
	void Teleport(AActor* interactor);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void StartMinigame(AActor* interactor);
public:




protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ClampMin = 0.0f, ClampMax = 1.0f, UIMin = 0.0f, UIMax = 1.0f))
		float signalFloat1 = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ClampMin = 0.0f, ClampMax = 1.0f, UIMin = 0.0f, UIMax = 1.0f))
		float signalFloat1Goal = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ClampMin = 0.0f, ClampMax = 9.0f, UIMin = 0.0f, UIMax = 9.0f))
		float signalFloat2 = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Meta = (ClampMin = 0.0f, ClampMax = 9.0f, UIMin = 0.0f, UIMax = 9.0f))
		float signalFloat2Goal = 9.0f;
	class USceneComponent* root;
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* tvmodel;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* screenmesh;
	UPROPERTY(EditAnywhere)
	class USceneComponent* destination;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(ClampMin=0.0f, ClampMax=1.0f, UIMin=0.0f, UIMax=1.0f))
	float signalStength = 0.0f;
};
