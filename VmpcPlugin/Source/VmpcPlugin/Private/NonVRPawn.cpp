// Fill out your copyright notice in the Description page of Project Settings.

#include "NonVRPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "KeyboardController.h"

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

}

// Called to bind functionality to input
void ANonVRPawn::SetupPlayerInputComponent(UInputComponent* pic)
{
	Super::SetupPlayerInputComponent(pic);
}

