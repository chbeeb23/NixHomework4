// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NixProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class NIXHOMEWORK4_API ANixProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	UProjectileMovementComponent* ProjectileMovement;
	
	// Sets default values for this actor's properties
	ANixProjectile();
};
