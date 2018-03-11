// Fill out your copyright notice in the Description page of Project Settings.

#include "VmpcMeshComponent.h"

#include <hardware/Hardware.hpp>
#include <hardware/Button.hpp>

void UVmpcMeshComponent::setMpc(AVmpc* vmpc) {
	this->vmpc = vmpc;
}

int UVmpcMeshComponent::getPadNr(std::string name) {
	if (name.length() > 3 && name.substr(0, 3).compare("pad") == 0) {
		try {
			if (name.length() == 4) {
				std::string candidate = name.substr(3, 1);
				int padNr = stoi(candidate);
				return padNr;
			}
			else if (name.length() == 5) {
				std::string candidate = name.substr(3, 2);
				int padNr = stoi(candidate);
				return padNr;
			}
		}
		catch (...) {
		}
	}
	return -1;
}

void UVmpcMeshComponent::triggerPush() {
	std::string name = std::string(TCHAR_TO_UTF8(*GetName()));
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	MLOG("Yay I'm pushed! Name is " + name);
	
	int pad = getPadNr(name);
	if (pad != -1) {
		vmpc->PadPush(pad);
		return;
	}
	
	if (GetName().StartsWith("Cursor")) {
		vmpc->ButtonPush(GetName().RightChop(6).ToLower());
		return;
	}

	vmpc->ButtonPush(GetName().ToLower());
}

void UVmpcMeshComponent::triggerRelease() {
	std::string name = std::string(TCHAR_TO_UTF8(*GetName()));
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	MLOG("Yay I'm released! Name is " + name);
	int pad = getPadNr(name);
	if (pad != -1) {
		vmpc->PadRelease(pad);
		return;
	}

	vmpc->ButtonRelease(GetName().ToLower());
}

void UVmpcMeshComponent::EnableOutline(bool b) {
	MLOG("Enable outline called");
	SetRenderCustomDepth(b);
}

void UVmpcMeshComponent::setPushable(bool b) {
	pushable = b;
}

bool UVmpcMeshComponent::isInteractable() {
	return pushable;
}

bool UVmpcMeshComponent::isPushable() {
	return pushable;
}

bool UVmpcMeshComponent::isPushed() {
	return pushed;
}
