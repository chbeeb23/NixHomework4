// Fill out your copyright notice in the Description page of Project Settings.


#include "NixPlayerController.h"

void ANixPlayerController::ContinueGame() const
{
	ContinueGameDelegate.Broadcast();
}

void ANixPlayerController::ExitGame() const
{
	ExitGameDelegate.Broadcast();
}

void ANixPlayerController::ChangePlayerName(const FText& Name) const
{
	PlayerNameChangedDelegate.Broadcast(Name);
}

void ANixPlayerController::ShowPlayerName(bool bState) const
{
	ShowPlayerNameDelegate.Broadcast(bState);
}
