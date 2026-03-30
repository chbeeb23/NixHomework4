// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "NixPawn.generated.h"


class ANixProjectile;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class NIXHOMEWORK4_API ANixPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANixPawn();

protected:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraComponent> CameraComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void InputMove(const FInputActionValue& InputActionValue);

	void InputZoom(const FInputActionValue& InputActionValue);

	void InputLook(const FInputActionValue& InputActionValue);
	
	void InputScale(const FInputActionValue& InputActionValue);
	
	void InputShoot(const FInputActionValue& InputActionValue);
	
	void InputRotateProjectile(const FInputActionValue& InputActionValue);
	
private:
	TObjectPtr<ANixProjectile> LastProjectile;

public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputMappingContext> InputMappingContext;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionMove;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionZoom;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionLook;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionScale;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionShoot;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionRotateProjectile;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ANixProjectile> ProjectileClass;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
