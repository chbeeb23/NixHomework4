// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/NixPauseMenuWidget.h"

#include "Kismet/KismetSystemLibrary.h"

void UNixPauseMenuWidget::ContinueGame() const
{
	HidePauseMenuDelegate.Broadcast();
}

void UNixPauseMenuWidget::ExitGame() const
{
	UKismetSystemLibrary::QuitGame(
	GetWorld(),
	GetWorld()->GetFirstPlayerController(),
	EQuitPreference::Quit,
	true);
}
