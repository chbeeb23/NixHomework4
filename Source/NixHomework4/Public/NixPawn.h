// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Interfaces/NixNamedInterface.h"
#include "NixPawn.generated.h"


class UWidgetComponent;
class ANixProjectile;
class UInputMappingContext;
class UInputAction;
class UCapsuleComponent;
struct FInputActionValue;

DECLARE_MULTICAST_DELEGATE(FDestoryActorsDelegate);
DECLARE_MULTICAST_DELEGATE(FShowPauseMenuDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNameSetup, const FText&, Name);

UCLASS()
class NIXHOMEWORK4_API ANixPawn : public APawn, public INixNamedInterface
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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UWidgetComponent> WidgetComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void InputMove(const FInputActionValue& InputActionValue);

	void InputZoom(const FInputActionValue& InputActionValue);

	void InputLook(const FInputActionValue& InputActionValue);
	
	void InputChangeColor(const FInputActionValue& InputActionValue);
	
	void InputShoot(const FInputActionValue& InputActionValue);
	
	void InputDestroy(const FInputActionValue& InputActionValue);
	
	void InputTraceLine(const FInputActionValue& InputActionValue);
	
	void InputPause(const FInputActionValue& InputActionValue);
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		FVector NormalImpulse, const FHitResult& Hit);
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
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
	TObjectPtr<UInputAction> InputActionChangeColor;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionShoot;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionDestroy;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionTraceLine;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputActionPause;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ANixProjectile> ProjectileClass;
	
	UPROPERTY(BlueprintReadOnly)
	FText PlayerName;
	
	UPROPERTY(BlueprintReadOnly)
	bool bShowName = false;
	
	FDestoryActorsDelegate DestoryActorsDelegate;
	
	FShowPauseMenuDelegate ShowPauseMenuDelegate;
	
	UPROPERTY(BlueprintAssignable)
	FOnNameSetup OnNameSetup;
	
	void SetupName_Implementation(const FText& Name);
	
	void ToggleShowName_Implementation(bool bShow=false);
	
	void UpdatePlayerNameVisibility(bool bForceHide=false) const;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
