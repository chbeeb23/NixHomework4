// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NixSettingsMenuWidget.generated.h"

class UEditableTextBox;
class UCheckBox;

/**
 * 
 */
UCLASS()
class NIXHOMEWORK4_API UNixSettingsMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct();

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* PlayerNameTextBox;

	UPROPERTY(meta = (BindWidget))
	UCheckBox* ShowPlayerNameCheckBox;

protected:
	UFUNCTION()
	void OnPlayerNameTextBlockChanged(const FText& Name);

	UFUNCTION()
	void OnShowPlayerNameCheckBoxStateChanged(bool bState);
};
