// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyboardController.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Vmpc.h"
#include <controls/Controls.hpp>

#include "Logger.hpp"

void AKeyboardController::setupInput() {
}

bool AKeyboardController::InputKey(FKey Key, EInputEvent EventType, float AmountDepressed, bool bGamepad) {

	TArray<AActor*> foundVmpcs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AVmpc::StaticClass(), foundVmpcs);
	// For now assume there's only 1 vmpc in the world.
	auto v = foundVmpcs[0];
	auto vmpc = Cast<AVmpc>(v);

	FString button("");
	std::vector<FKey> pads{ EKeys::Z, EKeys::X, EKeys::C, EKeys::V, EKeys::A, EKeys::S, EKeys::D, EKeys::F, EKeys::B, EKeys::N, EKeys::M, EKeys::Comma, EKeys::G, EKeys::H, EKeys::J, EKeys::K };
	std::vector<FKey> numbers{ EKeys::Zero, EKeys::One, EKeys::Two, EKeys::Three, EKeys::Four, EKeys::Five, EKeys::Six, EKeys::Seven, EKeys::Eight, EKeys::Nine };
	std::vector<FKey> functionKeys{ EKeys::F1, EKeys::F2, EKeys::F3, EKeys::F4, EKeys::F5, EKeys::F6 };

	// Cursor
	if (Key == EKeys::NumPadEight) {
		button = "up";
	}
	else if (Key == EKeys::NumPadTwo) {
		button = "down";
	}
	else if (Key == EKeys::NumPadFour) {
		button = "left";
	}
	else if (Key == EKeys::NumPadSix) {
		button = "right";
	}

	// Shift
	if (Key == EKeys::LeftShift || Key == EKeys::RightShift) {
		button = "shift";
	}

	// Numbers
	for (int i = 0; i < numbers.size(); i++) {
		if (Key == numbers[i]) {
			button = FString(std::to_string(i).c_str());
			break;
		}
	}

	// Function keys
	for (int i = 0; i < functionKeys.size(); i++) {
		if (Key == functionKeys[i]) {
			button = "f" + FString(std::to_string(i + 1).c_str());
			break;
		}
	}

	// Transport
	if (Key == EKeys::Backslash) {
		button = "playstart";
	}
	else if (Key == EKeys::SpaceBar) {
		button = "play";
	}
	else if (Key == EKeys::Apostrophe || Key == EKeys::Quote) {
		button = "stop";
	}
	else if (Key == EKeys::L) {
		button = "record";
	}
	else if (Key == EKeys::Semicolon) {
		button = "overdub";
	}

	// add open window & main screen. can I replace ESC == 'return to editor' with something else?


	/*
	* 'Push' section
	*/

	if (EventType == EInputEvent::IE_Pressed) {
		int increment = 1;
		auto controls = vmpc->mpcInst->getControls().lock();
		if (controls->isShiftPressed()) increment *= 10;
		if (controls->isAltPressed()) increment *= 10;
		if (controls->isCtrlPressed()) increment *= 10;
		// DataWheel
		if (Key == EKeys::Equals || Key == EKeys::Add) {
			vmpc->DataWheelTurn(increment);
			return true;
		}
		else if (Key == EKeys::Hyphen || Key == EKeys::Subtract) {
			vmpc->DataWheelTurn(-increment);
			return true;
		}

		// Pads
		for (int i = 0; i < pads.size(); i++) {
			if (Key == pads[i]) {
				vmpc->PadPush(i + 1);
				return true;
			}
		}

		// Button
		if (!button.Equals("")) {
			vmpc->ButtonPush(button);
			return true;
		}

	}


	/*
	* 'Release' section
	*/

	if (EventType == EInputEvent::IE_Released) {

		// DataWheel doesn't care about releases

		// Pads
		for (int i = 0; i < pads.size(); i++) {
			if (Key == pads[i]) {
				vmpc->PadRelease(i + 1);
				return true;
			}
		}

		// Button
		if (!button.Equals("")) {
			vmpc->ButtonRelease(button);
			return true;
		}

	}

	return Super::InputKey(Key, EventType, AmountDepressed, bGamepad);
}
