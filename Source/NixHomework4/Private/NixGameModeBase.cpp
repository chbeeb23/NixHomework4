// Fill out your copyright notice in the Description page of Project Settings.


#include "NixGameModeBase.h"

#include "Widgets/NixPauseMenuWidget.h"
#include "NixPawn.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void ANixGameModeBase::RegisterPawn(ANixPawn* Pawn)
{
	Pawn->ShowPauseMenuDelegate.AddUObject(this, &ANixGameModeBase::OnShowPauseMenuCallback);
}

void ANixGameModeBase::OnShowPauseMenuCallback()
{
	if (PauseMenuWidgetClass)
	{
		if (!PauseMenuWidget)
		{
			PauseMenuWidget = CreateWidget<UNixPauseMenuWidget>(GetWorld(), PauseMenuWidgetClass);
			PauseMenuWidget.Get()->HidePauseMenuDelegate.AddUObject(this, &ANixGameModeBase::OnHidePauseMenuCallback);
		}
		if (IsValid(PauseMenuWidget))
		{
			PauseMenuWidget->AddToViewport();
			PauseMenuWidget->Init();
			UGameplayStatics::SetGamePaused(GetWorld(), true);
			
			auto PlayerController = GetWorld()->GetFirstPlayerController();
			ensure(PlayerController);
			
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
