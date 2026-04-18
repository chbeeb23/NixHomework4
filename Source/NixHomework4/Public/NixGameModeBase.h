// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NixGameModeBase.generated.h"

class ANixPawn;
class UNixPauseMenuWidget;
/**
 * 
 */
UCLASS()
class NIXHOMEWORK4_API ANixGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UNixPauseMenuWidget> PauseMenuWidgetClass;

	UPROPERTY()
	TObjectPtr<UNixPauseMenuWidget> PauseMenuWidget;
	
	void RegisterPawn(ANixPawn* Pawn);
	
protected:
	UFUNCTION()
	void OnShowPauseMenuCallback();
	
	UFUNCTION()
	void OnHidePauseMenuCallback();

	UFUNCTION()
	void OnExitGameCallback();

	UFUNCTION()
	void OnPlayerNameChangedCallback(const FText& Name);

	UFUNCTION()
	void OnShowPlayerName(bool bShow);
};
