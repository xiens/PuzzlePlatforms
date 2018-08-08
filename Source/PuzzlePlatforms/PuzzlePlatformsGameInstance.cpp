// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "PlatformTrigger.h"
#include "Blueprint/UserWidget.h"
#include "MenuSystem/MainMenu.h"
#include "MenuSystem/InGameMenu.h"
#include "MenuSystem/Menu.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectIn) {

	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuWidgetBP(TEXT("/Game/MenuSystem/MainMenu_BP"));
	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuWidgetBP(TEXT("/Game/MenuSystem/InGameMenu_BP"));
	
	MainMenuClass = MainMenuWidgetBP.Class;
	InGameMenuClass = InGameMenuWidgetBP.Class;
}


void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Init"))
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{
	if (!MainMenuClass) return;
	MainMenu = CreateWidget<UMainMenu>(this, MainMenuClass);

	MainMenu->Setup();

	MainMenu->SetMenuInterface(this);


}

void UPuzzlePlatformsGameInstance::LoadInGameMenu()
{
	if (!InGameMenuClass) return;
	InGameMenu = CreateWidget<UInGameMenu>(this, InGameMenuClass);

	InGameMenu->Setup();

	InGameMenu->SetMenuInterface(this);

}

void UPuzzlePlatformsGameInstance::LoadMainMenu()
{
	APlayerController * PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/Maps/MainMenu", TRAVEL_Partial);
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	Engine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("This is an on screen message!"));
	
	GetWorld()->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString &Address)
{
	UEngine* Engine = GetEngine();

	Engine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Joining, %s"), *Address));
	
	APlayerController * PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;
	
	PlayerController->ClientTravel(Address,TRAVEL_Partial);
}

