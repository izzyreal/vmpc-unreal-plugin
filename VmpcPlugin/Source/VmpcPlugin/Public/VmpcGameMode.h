// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VmpcGameMode.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API AVmpcGameMode : public AGameModeBase
{
	GENERATED_BODY()

	void PostLogin(APlayerController* NewPlayer) override;
	APlayerController* SpawnPlayerController(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation) override;
	//DefaultPawnClass = ASomePawn::StaticClass();
	//PlayerControllerClass = ASomePlayerController::StaticClass();
};
