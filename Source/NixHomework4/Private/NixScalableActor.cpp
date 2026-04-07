// Fill out your copyright notice in the Description page of Project Settings.


#include "NixScalableActor.h"

#include "NixPawn.h"


// Sets default values
ANixScalableActor::ANixScalableActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = StaticMeshComponent;
}

void ANixScalableActor::BeginPlay()
{
	Super::BeginPlay();
	
	Cast<ANixPawn>(GetWorld()->GetFirstPlayerController()->GetPawn())->DestoryActorsDelegate.AddUObject(this,
		&ANixScalableActor::OnDestroyActorsCallbacl);
}

void ANixScalableActor::OnDestroyActorsCallbacl()
{
	Destroy();
}

void ANixScalableActor::OnInteract_Implementation()
{
	auto CurrentScale = GetActorScale3D();
	auto Scale = FMath::IsNearlyEqual(CurrentScale.X, 1.0f) ? 0.5f : 2.f;
	SetActorScale3D(CurrentScale * Scale);
}


