// Fill out your copyright notice in the Description page of Project Settings.

#include "NonVRPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"

#include "KeyboardController.h"
#include "VmpcMeshComponent.h"

#include <Logger.hpp>

#include <string>

// Sets default values
ANonVRPawn::ANonVRPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoReceiveInput = EAutoReceiveInput::Player0;
	SetActorRotation(FRotator(0.0f, -90.0f, 0.0f));
}

// Called when the game starts or when spawned
void ANonVRPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANonVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult RV_Hit(ForceInit);
	if (Cast<AKeyboardController>(Controller)->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, RV_Hit)) {
		auto comp = RV_Hit.GetComponent();
		if (comp->IsValidLowLevelFast() && Cast<UVmpcMeshComponent>(comp) != nullptr) {
			auto vmpcComp = Cast<UVmpcMeshComponent>(comp);
			//std::string name = std::string(TCHAR_TO_UTF8(*comp->GetName()));
			//MLOG("Component hit name: " + name);
			if (vmpcComp != currentHighlightedComponent) {
				if (currentHighlightedComponent != nullptr) {
					currentHighlightedComponent->EnableOutline(false);
				}
				if (vmpcComp->isInteractable()) {
					currentHighlightedComponent = vmpcComp;
					currentHighlightedComponent->EnableOutline(true);
				}
				else {
					currentHighlightedComponent = nullptr;
				}
			}
		}
		else {
			if (currentHighlightedComponent != nullptr) {
				currentHighlightedComponent->EnableOutline(false);
				currentHighlightedComponent = nullptr;
			}
		}
	}
}

// Called to bind functionality to input
void ANonVRPawn::SetupPlayerInputComponent(UInputComponent* pic)
{
	Super::SetupPlayerInputComponent(pic);
}
