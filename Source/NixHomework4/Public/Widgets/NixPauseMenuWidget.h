// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NixPauseMenuWidget.generated.h"


DECLARE_MULTICAST_DELEGATE(FHidePauseMenuDelegate);

/**
 * 
 */
UCLASS()
class NIXHOMEWORK4_API UNixPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	FHidePauseMenuDelegate HidePauseMenuDelegate;
	
	UFUNCTION(BlueprintCallable)
	void ContinueGame() const;
	
	UFUNCTION(BlueprintCallable)
	void ExitGame() const;
	
	UFUNCTION(BlueprintImplementableEvent)
	void Init();
};
