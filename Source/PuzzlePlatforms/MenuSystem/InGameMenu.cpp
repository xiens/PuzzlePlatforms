// Fill out your copyright notice in the Description page of Project Settings.

#include "InGameMenu.h"
#include "Components/Button.h"



bool UInGameMenu::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) return false;


	if (!LoadMainMenuButton) return false;
	LoadMainMenuButton->OnClicked.AddDynamic(this, &UInGameMenu::LoadMainMenu);
	if (!CancelButton) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::Cancel);

	return true;
}


void UInGameMenu::LoadMainMenu(){
		if (MenuInterface != nullptr) {
			Cancel();
			MenuInterface->LoadMainMenu();
			/*APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
			if (!ensure(PlayerController != nullptr)) return;

			PlayerController->ClientTravel("/Game/Maps/MainMenu", TRAVEL_Partial);*/
		}
}

void UInGameMenu::Cancel(){
	
	//Set player input, hide mouse cursor
	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly 	GameInputMode;
	PlayerController->SetInputMode(GameInputMode);

	PlayerController->bShowMouseCursor = false;
	this->RemoveFromViewport();
}