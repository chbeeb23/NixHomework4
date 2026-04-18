// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NixPauseMenuWidget.generated.h"


class UButton;
class UWidgetSwitcher;


/**
 * 
 */
UCLASS()
class NIXHOMEWORK4_API UNixPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct();

	UPROPERTY(meta = (BindWidget))
	UButton* MainMenuButton;

	UPROPERTY(meta = (BindWidget))
	UButton* SettingsMenuButton;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* WidgetSwitcher;
	
	void Init();

protected:
	UFUNCTION()
	void OnMainMenuButtonClicked();

	UFUNCTION()
	void OnSettingsMenuButtonClicked();
};
