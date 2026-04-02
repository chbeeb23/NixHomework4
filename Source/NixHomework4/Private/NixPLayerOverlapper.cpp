// Fill out your copyright notice in the Description page of Project Settings.


#include "NixPLayerOverlapper.h"


// Sets default values
ANixPLayerOverlapper::ANixPLayerOverlapper()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticMeshComponent->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	StaticMeshComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	StaticMeshComponent->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	StaticMeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	StaticMeshComponent->SetCollisionResponseToChannel(ECC_Visibility, ECR_Overlap);
	
	RootComponent = StaticMeshComponent;
}


