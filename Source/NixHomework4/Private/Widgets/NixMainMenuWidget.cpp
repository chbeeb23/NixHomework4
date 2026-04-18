// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/NixMainMenuWidget.h"
#include "Components/Button.h"
#include <NixPlayerController.h>

void UNixMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ContinueButton)
	{
		ContinueButton->OnClicked.AddDynamic(this, &UNixMainMenuWidget::OnContinueButtonClicked);
	}

	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UNixMainMenuWidget::OnExitButtonClicked);
	}
}

void UNixMainMenuWidget::OnContinueButtonClicked()
{
	if (auto PlayerController = Cast<ANixPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PlayerController->ContinueGame();
	}
}

void UNixMainMenuWidget::OnExitButtonClicked()
{
	if (auto PlayerController = Cast<ANixPlayerController>(GetWorld()->GetFirstPlayerController()))
	{
		PlayerController->ExitGame();
	}
}
