// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/NixInteractionInterfce.h"
#include "NixScalableActor.generated.h"

UCLASS()
class NIXHOMEWORK4_API ANixScalableActor : public AActor, public INixInteractionInterfce
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANixScalableActor();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnDestroyActorsCallbacl();
	
public:
	void OnInteract_Implementation();
};
