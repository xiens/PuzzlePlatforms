// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Menu.h"
#include "MenuInterface.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UInGameMenu : public UMenu
{
	GENERATED_BODY()

	
protected:
	virtual bool Initialize() override;

	UFUNCTION()
	void Cancel();

	UFUNCTION()
	void LoadMainMenu();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton * CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton * LoadMainMenuButton;
	
	
};
