// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NixMainMenuWidget.generated.h"

class UButton;

/**
 * 
 */
UCLASS()
class NIXHOMEWORK4_API UNixMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct();

	UPROPERTY(meta = (BindWidget))
	UButton* ContinueButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton;

protected:
	UFUNCTION()
	void OnContinueButtonClicked();

	UFUNCTION()
	void OnExitButtonClicked();
};
