// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "Interfaces/NixInteractionInterfce.h"
#include "NixLightActor.generated.h"

class UPointLightComponent;

UCLASS()
class NIXHOMEWORK4_API ANixLightActor : public AActor, public INixInteractionInterfce
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANixLightActor();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UPointLightComponent> PointLightComponent;
	
	UPROPERTY(EditDefaultsOnly)
	UCurveLinearColor* ColorCurve;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void HandleColorProgress(FLinearColor Value);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void OnInteract_Implementation();
	
private:
	FTimeline ColorTimeline;
};
