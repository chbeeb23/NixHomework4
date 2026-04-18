// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/NixPauseMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"


void UNixPauseMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (MainMenuButton)
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UNixPauseMenuWidget::OnMainMenuButtonClicked);
	}

	if (SettingsMenuButton)
	{
		SettingsMenuButton->OnClicked.AddDynamic(this, &UNixPauseMenuWidget::OnSettingsMenuButtonClicked);
	}
}

void UNixPauseMenuWidget::Init()
{
	WidgetSwitcher->SetVisibility(ESlateVisibility::Hidden);
}

void UNixPauseMenuWidget::OnMainMenuButtonClicked()
{
	WidgetSwitcher->SetVisibility(ESlateVisibility::Visible);
	WidgetSwitcher->SetActiveWidgetIndex(0);
}

void UNixPauseMenuWidget::OnSettingsMenuButtonClicked()
{
	WidgetSwitcher->SetVisibility(ESlateVisibility::Visible);
	WidgetSwitcher->SetActiveWidgetIndex(1);
}
