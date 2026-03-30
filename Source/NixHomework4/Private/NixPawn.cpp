// Fill out your copyright notice in the Description page of Project Settings.


#include "NixHomework4/Public/NixPawn.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "NixProjectile.h"


#define SCALE_MULTIPLIER 0.01

// Sets default values
ANixPawn::ANixPawn() : LastProjectile(nullptr)
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void ANixPawn::BeginPlay()
{
	Super::BeginPlay();
	if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		if(UEnhancedInputLocalPlayerSubsystem* InputLocalPlayerSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputLocalPlayerSubsystem->AddMappingContext(InputMappingContext, 1);
		}
	}
}

void ANixPawn::InputMove(const FInputActionValue& InputActionValue)
{
	const FVector2D& MovementVector = InputActionValue.Get<FVector2D>();

	// Forward/backward movement
	SetActorLocation(GetActorLocation() + GetActorForwardVector() * MovementVector.Y);

	// Left/right movement
	SetActorLocation(GetActorLocation() + GetActorRightVector() * MovementVector.X);
}

void ANixPawn::InputZoom(const FInputActionValue& InputActionValue)
{
	float ZoomValue = InputActionValue.Get<float>();

	float NewTargetArmLength = SpringArmComponent->TargetArmLength + ZoomValue;
	SpringArmComponent->TargetArmLength = FMath::Clamp(NewTargetArmLength, 200, 500);
}

void ANixPawn::InputLook(const FInputActionValue& InputActionValue)
{
	FVector2D LookAxisVector=InputActionValue.Get<FVector2D>();

	AddControllerYawInput(LookAxisVector.X);
	AddControllerPitchInput(LookAxisVector.Y);
}

void ANixPawn::InputScale(const FInputActionValue& InputActionValue)
{
	float ScaleValue = InputActionValue.Get<float>() * SCALE_MULTIPLIER;
	float NewScale = FMath::Clamp(ScaleValue + GetActorScale().X, 0.25, 2.0);
	
	SetActorScale3D(FVector3d(NewScale, NewScale, NewScale));
}

void ANixPawn::InputShoot(const FInputActionValue& InputActionValue)
{
	bool ShootValue = InputActionValue.Get<bool>();
	
	if (ShootValue && ProjectileClass)
	{
		FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.f;
		FRotator SpawnRotation = GetControlRotation();

		FActorSpawnParameters Params;
		Params.Owner = this;
		Params.Instigator = GetInstigator();

		LastProjectile = GetWorld()->SpawnActor<ANixProjectile>(
			ProjectileClass,
			SpawnLocation,
			SpawnRotation,
			Params
		);
	}
}

void ANixPawn::InputRotateProjectile(const FInputActionValue& InputActionValue)
{
	bool RotateValue = InputActionValue.Get<bool>();
	
	if (RotateValue && LastProjectile)
	{
		LastProjectile->AddActorLocalRotation(FRotator(5.f, 0.f, 0.f));
	}
}

// Called to bind functionality to input
void ANixPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if(UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputActionMove, ETriggerEvent::Triggered, this, &ThisClass::InputMove);
		Input->BindAction(InputActionZoom, ETriggerEvent::Triggered, this, &ThisClass::InputZoom);
		Input->BindAction(InputActionLook, ETriggerEvent::Triggered, this, &ThisClass::InputLook);
		Input->BindAction(InputActionScale, ETriggerEvent::Triggered, this, &ThisClass::InputScale);
		Input->BindAction(InputActionShoot, ETriggerEvent::Triggered, this, &ThisClass::InputShoot);
		Input->BindAction(InputActionRotateProjectile, ETriggerEvent::Triggered, this, &ThisClass::InputRotateProjectile);
	}
}

