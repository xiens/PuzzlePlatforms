// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenu.h"
#include"Components/Button.h"
#include"Components/WidgetSwitcher.h"
#include"Components/Widget.h"
#include"Components/EditableTextBox.h"
#include "Engine/World.h"




bool UMainMenu::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) return false;

	//Setup
	if (!HostButton) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	if (!OpenJoinMenuButton) return false;
	OpenJoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	if (!JoinButton) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::Join);
	if (!CancelButton) return false;
	CancelButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);
	if (!QuitButton) return false;
	QuitButton->OnClicked.AddDynamic(this, &UMainMenu::Quit);
	

	return true;
}


void UMainMenu::HostServer(){

		if (MenuInterface != nullptr) {
			MenuInterface->Host();
		}
}

void UMainMenu::OpenJoinMenu() {
	
	if (!MenuSwitcher) return;
	MenuSwitcher->SetActiveWidget(JoinMenuWidget);
}

void UMainMenu::OpenMainMenu(){
	if (!MenuSwitcher) return;
	MenuSwitcher->SetActiveWidget(MainMenuWidget);
}

void UMainMenu::Join()
{
	if (!IPTextBox) return;
	FText IPAddress = IPTextBox->GetText();
	FString IPAddressString = IPAddress.ToString();
	if (MenuInterface != nullptr) {
		MenuInterface->Join(IPAddressString);
	}
}

void UMainMenu::Quit()
{
	APlayerController * PlayerController;
	PlayerController = GetWorld()->GetFirstPlayerController();

	if (!PlayerController) return;
	PlayerController->ConsoleCommand("quit");

}








