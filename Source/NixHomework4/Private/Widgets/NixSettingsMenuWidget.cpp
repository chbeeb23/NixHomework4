// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/NixSettingsMenuWidget.h"
#include "Components/EditableTextBox.h"
#include <NixPlayerController.h>
#include "Components/CheckBox.h"

void UNixSettingsMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (PlayerNameTextBox)
    {
        PlayerNameTextBox->OnTextChanged.AddDynamic(
            this,
            &UNixSettingsMenuWidget::OnPlayerNameTextBlockChanged
        );
    }

    if (ShowPlayerNameCheckBox)
    {
        ShowPlayerNameCheckBox->OnCheckStateChanged.AddDynamic(
            this,
            &UNixSettingsMenuWidget::OnShowPlayerNameCheckBoxStateChanged
        );
    }
}

void UNixSettingsMenuWidget::OnPlayerNameTextBlockChanged(const FText& Name)
{
    if (auto PlayerController = Cast<ANixPlayerController>(GetWorld()->GetFirstPlayerController()))
    {
        PlayerController->ChangePlayerName(Name);
    }
}

void UNixSettingsMenuWidget::OnShowPlayerNameCheckBoxStateChanged(bool bState)
{
    if (auto PlayerController = Cast<ANixPlayerController>(GetWorld()->GetFirstPlayerController()))
    {
        PlayerController->ShowPlayerName(bState);
    }
}
