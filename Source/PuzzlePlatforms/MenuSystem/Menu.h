// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "Menu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetMenuInterface(IMenuInterface * MenuInterfaceToSet);

	void Setup();

	virtual void OnLevelRemovedFromWorld(ULevel * InLevel, UWorld * InWorld) override;
	
protected:
	IMenuInterface * MenuInterface;
};
