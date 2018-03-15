// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KeyboardController.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API AKeyboardController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	void BeginPlay() override;

public:
	bool InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad) override;

};
