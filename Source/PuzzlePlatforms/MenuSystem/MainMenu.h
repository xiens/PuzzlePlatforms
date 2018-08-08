// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Menu.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenu
{
	GENERATED_BODY()


protected:
	virtual bool Initialize() override;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void Join();

	UFUNCTION()
	void Quit();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton * HostButton;
	
	UPROPERTY(meta = (BindWidget))
	class UButton * JoinButton;

	UPROPERTY(meta = (BindWidget))
	class UButton * OpenJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton * CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton * QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher * MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	class UWidget * JoinMenuWidget;

	UPROPERTY(meta = (BindWidget))
	class UWidget * MainMenuWidget;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox * IPTextBox;


};
