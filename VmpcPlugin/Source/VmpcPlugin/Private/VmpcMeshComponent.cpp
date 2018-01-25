// Fill out your copyright notice in the Description page of Project Settings.

#include "VmpcMeshComponent.h"

#include <hardware/Hardware.hpp>
#include <hardware/Button.hpp>

void UVmpcMeshComponent::setMpc(UVmpcAudioComponent* mpc) {
	this->mpc = mpc;
}

void UVmpcMeshComponent::push() {
	std::string name = std::string(TCHAR_TO_UTF8(*GetName()));
	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	MLOG("Yay I'm pushed! Name is " + name);
	mpc->Button(GetName().ToLower());
}

void UVmpcMeshComponent::EnableOutline(bool b) {
	if (GetName().Equals("Body")) return;
	if (GetName().Equals("Display")) return;
	SetRenderCustomDepth(b);
}
