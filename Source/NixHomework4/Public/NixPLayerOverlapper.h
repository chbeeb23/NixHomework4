// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NixPLayerOverlapper.generated.h"

UCLASS()
class NIXHOMEWORK4_API ANixPLayerOverlapper : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANixPLayerOverlapper();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;
};
