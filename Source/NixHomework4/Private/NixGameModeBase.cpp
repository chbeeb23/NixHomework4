// Fill out your copyright notice in the Description page of Project Settings.


#include "NixGameModeBase.h"

#include "Widgets/NixPauseMenuWidget.h"
#include "NixPawn.h"
#include "Blueprint/UserWidget.h"
#include <NixPlayerController.h>
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"


void ANixGameModeBase::RegisterPawn(ANixPawn* Pawn)
{
	Pawn->ShowPauseMenuDelegate.AddUObject(this, &ANixGameModeBase::OnShowPauseMenuCallback);
}

void ANixGameModeBase::OnShowPauseMenuCallback()
{
	if (PauseMenuWidgetClass)
	{
		auto PlayerController = GetWorld()->GetFirstPlayerController();
		ensure(PlayerController);

		if (!PauseMenuWidget)
		{
			PauseMenuWidget = CreateWidget<UNixPauseMenuWidget>(GetWorld(), PauseMenuWidgetClass);
			if (auto NixPlayerController = Cast<ANixPlayerController>(PlayerController))
			{
				NixPlayerController->ContinueGameDelegate.AddUObject(this, &ANixGameModeBase::OnHidePauseMenuCallback);
				NixPlayerController->ExitGameDelegate.AddUObject(this, &ANixGameModeBase::OnExitGameCallback);
				NixPlayerController->PlayerNameChangedDelegate.AddUObject(this, &ANixGameModeBase::OnPlayerNameChangedCallback);
				NixPlayerController->ShowPlayerNameDelegate.AddUObject(this, &ANixGameModeBase::OnShowPlayerName);
			}
		}
		if (IsValid(PauseMenuWidget))
		{
			PauseMenuWidget->AddToViewport();
			PauseMenuWidget->Init();
			UGameplayStatics::SetGamePaused(GetWorld(), true);
			
			PlayerController->SetShowMouseCursor(true);
			PlayerController->SetInputMode(FInputModeUIOnly());
			
			if (ANixPawn* Pawn = Cast<ANixPawn>(PlayerController->GetPawn()))
			{
				Pawn->UpdatePlayerNameVisibility(true);
			}
		}
	}
}

void ANixGameModeBase::OnHidePauseMenuCallback()
{
	PauseMenuWidget->RemoveFromParent();
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	
	auto PlayerController = GetWorld()->GetFirstPlayerController();
	ensure(PlayerController);
			
	PlayerController->SetShowMouseCursor(false);
	PlayerController->SetInputMode(FInputModeGameOnly());
	
	if (ANixPawn* Pawn = Cast<ANixPawn>(PlayerController->GetPawn()))
	{
		Pawn->UpdatePlayerNameVisibility();
	}
}

void ANixGameModeBase::OnExitGameCallback()
{
	UKismetSystemLibrary::QuitGame(
		GetWorld(),
		GetWorld()->GetFirstPlayerController(),
		EQuitPreference::Quit,
		true);
}

void ANixGameModeBase::OnPlayerNameChangedCallback(const FText& Name)
{
	if (auto Pawn = GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		if (Pawn->Implements<UNixNamedInterface>())
		{
			INixNamedInterface::Execute_SetupName(Pawn, Name);
		}
	}
}

void ANixGameModeBase::OnShowPlayerName(bool bShow)
{
	if (auto Pawn = GetWorld()->GetFirstPlayerController()->GetPawn())
	{
		if (Pawn->Implements<UNixNamedInterface>())
		{
			INixNamedInterface::Execute_ToggleShowName(Pawn, bShow);
		}
	}
}
