// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MenuSystem/MenuInterface.h"
#include "Engine/World.h"
#include "PuzzlePlatformsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer & ObjectIn);

	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	//IMenuInterface
	UFUNCTION(BlueprintCallable)
		virtual void Host() override;

	UFUNCTION(BlueprintCallable)
		virtual void Join(const FString &Address) override;

	UFUNCTION(BlueprintCallable)
		virtual void LoadMainMenu() override;

private:
	TSubclassOf<UUserWidget> MainMenuClass;

	TSubclassOf<UUserWidget> InGameMenuClass;

	class UMainMenu * MainMenu;

	class UInGameMenu * InGameMenu;
};
