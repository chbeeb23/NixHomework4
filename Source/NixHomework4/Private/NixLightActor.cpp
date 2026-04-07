// Fill out your copyright notice in the Description page of Project Settings.


#include "NixLightActor.h"

#include "Components/LightComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/TimelineComponent.h"


// Sets default values
ANixLightActor::ANixLightActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	PointLightComponent = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLightComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANixLightActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (ColorCurve)
	{
		FOnTimelineLinearColor ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleColorProgress"));

		ColorTimeline.AddInterpLinearColor(ColorCurve, ProgressFunction);
		ColorTimeline.SetLooping(true); // если нужно
	}
}

void ANixLightActor::HandleColorProgress(FLinearColor Value)
{
	if (PointLightComponent)
	{
		PointLightComponent->SetLightColor(Value);
	}
}

// Called every frame
void ANixLightActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ColorTimeline.TickTimeline(DeltaTime);
}

void ANixLightActor::OnInteract_Implementation()
{
	ColorTimeline.PlayFromStart();
}

