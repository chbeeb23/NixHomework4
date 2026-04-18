// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NixPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE(FMenuButtonGameDelegate);
DECLARE_MULTICAST_DELEGATE_OneParam(FEditableTextBoxChangedDelegate, const FText&);
DECLARE_MULTICAST_DELEGATE_OneParam(FCheckBoxStateChanged, bool);

/**
 * 
 */
UCLASS()
class NIXHOMEWORK4_API ANixPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	FMenuButtonGameDelegate ContinueGameDelegate;

	FMenuButtonGameDelegate ExitGameDelegate;

	FEditableTextBoxChangedDelegate PlayerNameChangedDelegate;

	FCheckBoxStateChanged ShowPlayerNameDelegate;

	void ContinueGame() const;

	void ExitGame() const;

	void ChangePlayerName(const FText& Name) const;

	void ShowPlayerName(bool bState) const;
};
