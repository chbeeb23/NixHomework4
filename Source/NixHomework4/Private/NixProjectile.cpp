// Fill out your copyright notice in the Description page of Project Settings.


#include "NixProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ANixProjectile::ANixProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ProjectileMovement->InitialSpeed = 250.f;
	ProjectileMovement->MaxSpeed = 250.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
}
