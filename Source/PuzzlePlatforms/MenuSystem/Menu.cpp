// Fill out your copyright notice in the Description page of Project Settings.

#include "Menu.h"
#include"Components/Widget.h"

void UMenu::Setup()
{
	this->AddToViewport();

	//Set player input, show mouse cursor
	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly UIInputMode;
	UIInputMode.SetWidgetToFocus(this->TakeWidget());
	UIInputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture);
	PlayerController->SetInputMode(UIInputMode);

	PlayerController->bShowMouseCursor = true;
}

// Method called when the world is being destroyed
//Override method, change the input mode to game only and hides the mouse cursor
void UMenu::OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld)
{
	Super::OnLevelRemovedFromWorld(InLevel, InWorld);

	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly GameInputMode;
	PlayerController->SetInputMode(GameInputMode);

	PlayerController->bShowMouseCursor = false;
}

void UMenu::SetMenuInterface(IMenuInterface * MenuInterfaceToSet) {
	MenuInterface = MenuInterfaceToSet;
}
