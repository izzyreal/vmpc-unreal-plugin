// Fill out your copyright notice in the Description page of Project Settings.

#include "VmpcGameMode.h"

#include "NonVRPawn.h"
#include "KeyboardController.h"

#include "Engine.h"
#include "IXRTrackingSystem.h"
#include "Runtime/HeadMountedDisplay/Public/IHeadMountedDisplay.h"

APlayerController* AVmpcGameMode::SpawnPlayerController(ENetRole InRemoteRole, FVector const& SpawnLocation, FRotator const& SpawnRotation) {
	PlayerControllerClass = AKeyboardController::StaticClass();
	bool hmdEnabled = false;
	if (GEngine) {
		auto xrSystem = GEngine->XRSystem;
		if (xrSystem.IsValid()) {
			auto hmdDevice = GEngine->XRSystem->GetHMDDevice();
			if (hmdDevice != nullptr) {
				hmdEnabled = hmdDevice->IsHMDEnabled();
			}
		}
	}
	if (hmdEnabled) {
		ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/VmpcPlugin/VRPlayer/AmbidextrousPawn.AmbidextrousPawn'"));
		if (ItemBlueprint.Object) {
			DefaultPawnClass = (UClass*)ItemBlueprint.Object->GeneratedClass;
		}
	}
	else {
		DefaultPawnClass = ANonVRPawn::StaticClass();
	}
	return AGameModeBase::SpawnPlayerController(InRemoteRole, SpawnLocation, SpawnRotation);
}

void AVmpcGameMode::PostLogin(APlayerController* NewPlayer) {
	//bool hmdEnabled = GEngine->XRSystem->GetHMDDevice()->IsHMDEnabled();
	//APawn* pawn;
	//NewPlayer->Possess(pawn);
	AGameModeBase::PostLogin(NewPlayer);
}
