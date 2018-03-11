// Fill out your copyright notice in the Description page of Project Settings.

#include "Vmpc.h"
#include "Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"

#include "Components/InstancedStaticMeshComponent.h"

#include "PhysicsEngine/BodySetup.h"

#include <audiomidi/AudioMidiServices.hpp>

#include <hardware/Hardware.hpp>
#include <hardware/DataWheel.hpp>
#include <hardware/Button.hpp>
#include <hardware/HwPad.hpp>

#include <sequencer/Sequencer.hpp>
#include <sequencer/Sequence.hpp>

#include <lcdgui/LayeredScreen.hpp>

#include <VmpcPlugin.h>

#include "LcdComponent.h"
#include "RotatingComponent.h"
#include "KnobComponent.h"
#include "VmpcMeshComponent.h"

#include <vector>

AVmpc::AVmpc()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	if (!mpcInst) {
		mpcInst = std::make_shared<mpc::Mpc>();
	}
	vmpcAudioComponent = CreateDefaultSubobject<UVmpcAudioComponent>("VmpcAudioComponent");
	vmpcAudioComponent->setMpc(mpcInst);
	vmpcAudioComponent->RegisterComponent();
	vmpcAudioComponent->SetupAttachment(RootComponent);

	DataWheelComponent = addRotatable("DataWheel", false);
	dataWheelObserver = std::make_shared<DataWheelObserver>(DataWheelComponent);
	mpcInst->getHardware().lock()->getDataWheel().lock()->addObserver(dataWheelObserver.get());

	RecGainComponent = (UKnobComponent*) addRotatable("RecGain", true);
	VolumeComponent = (UKnobComponent*)addRotatable("Volume", true);

	addDisplay();

	std::vector<FString> pushableMeshNames{ "After", "BankA", "BankB", "BankC", "BankD", "BarEnd", "BarStart", "Enter", "Erase", "F1", "F2", "F3", "F4", "F5", "F6", "FullLevel", "GoTo", "MainScreen", "NextSeq", "NextStep", "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "OpenWindow", "Overdub", "Play", "PlayStart", "PrevStep", "Rec", "Shift", "SixteenLevels", "Stop", "Tap", "TrackMute", "UndoSeq" };
	
	for (auto& s : pushableMeshNames) {
		auto mesh = addMesh(s);
		if (mesh->GetStaticMesh()->IsValidLowLevel()) {
			mesh->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;
			mesh->setPushable(true);
		}
	}

	//std::vector<FString> nonInteractableMeshNames{ "Pads", "Cursor", "Body", "FrontPanel", "DisplayCase", "DisplayDock", "DisplayFoil", "DisplayWindow" };
	std::vector<FString> nonInteractableMeshNames{ "Pads", "Cursor", "Body", "FrontPanel", "DisplayCase", "DisplayDock", "DisplayFoil" }; 
	for (auto& s : nonInteractableMeshNames) {
		auto mesh = addMesh(s);
		if (mesh->GetStaticMesh()->IsValidLowLevel()) {
			mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}

	std::vector<FString> invisibleMeshNames{ "CursorLeft", "CursorRight", "CursorUp", "CursorDown", "Pad1", "Pad2", "Pad3", "Pad4", "Pad5", "Pad6", "Pad7", "Pad8", "Pad9", "Pad10", "Pad11", "Pad12", "Pad13", "Pad14", "Pad15", "Pad16" };
	for (auto& s : invisibleMeshNames) {
		auto mesh = addMesh(s);
		if (mesh->GetStaticMesh()->IsValidLowLevel()) {
			mesh->SetRenderInMainPass(false);
			mesh->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;
			mesh->SetCastShadow(false);
		}
	}
	addMesh("Slider");
}

void AVmpc::addDisplay() {
	FString fullName = "mpc_DisplayLcd";
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";
	DisplayLcd = CreateDefaultSubobject<ULcdComponent>("DisplayLcd");
	DisplayLcd->setMpc(mpcInst);
	DisplayLcd->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(*fullName);
	if (!StaticMesh.Succeeded()) return;
	DisplayLcd->SetStaticMesh(StaticMesh.Object);
	DisplayLcd->RegisterComponent();
	DisplayLcd->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UVmpcMeshComponent* AVmpc::addMesh(FString name) {
	FString fullName = "mpc_" + name;
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";
	UVmpcMeshComponent* MeshComponent = CreateDefaultSubobject<UVmpcMeshComponent>(*name);
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(*fullName);
	if (!StaticMesh.Succeeded()) return MeshComponent;
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetStaticMesh(StaticMesh.Object);
	MeshComponent->setMpc(this);
	MeshComponent->RegisterComponent();
	MeshComponent->bOverrideLightMapRes = true;
	MeshComponent->OverriddenLightMapRes = 512;
	if (name.Equals("Body")) BodyComponent = MeshComponent;
	return MeshComponent;
}

URotatingComponent* AVmpc::addRotatable(FString name, bool knob) {
	FString fullName = "mpc_" + name;
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";
	URotatingComponent* rotatableComponent;
	if (knob) {
		rotatableComponent = CreateDefaultSubobject<UKnobComponent>(*name);
	}
	else {
		rotatableComponent = CreateDefaultSubobject<URotatingComponent>(*name);
	}
	
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(*fullName);
	if (!StaticMesh.Succeeded()) return rotatableComponent;
	rotatableComponent->SetupAttachment(RootComponent);
	rotatableComponent->SetStaticMesh(StaticMesh.Object);
	rotatableComponent->setMpc(this);
	rotatableComponent->SetMobility(EComponentMobility::Movable);
	rotatableComponent->RegisterComponent();
	auto pivot = addMesh("Pivot" + name);
	pivot->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	pivot->SetRenderInMainPass(false);
	pivot->SetCastShadow(false);
	rotatableComponent->setPivot(pivot);
	return rotatableComponent;
}

void AVmpc::BeginPlay()
{
	Super::BeginPlay();
	vmpcAudioComponent->Start();

	auto pot = mpcInst->getHardware().lock()->getRecPot();
	auto level = mpcInst->getAudioMidiServices().lock()->getRecordLevel();

	RecGainComponent->setPot(pot);
	RecGainComponent->SetValue(level);

	pot = mpcInst->getHardware().lock()->getVolPot();
	level = mpcInst->getAudioMidiServices().lock()->getMasterLevel();
	VolumeComponent->setPot(pot);
	VolumeComponent->SetValue(level);
}

void AVmpc::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (DisplayLcd->IsValidLowLevelFast()) {
		DisplayLcd->CreateTexture(false);
		DisplayLcd->UpdateTexture();
	}
}

void AVmpc::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (DisplayLcd->IsValidLowLevelFast()) {
		DisplayLcd->CreateTexture(true);
		DisplayLcd->UpdateTexture();
	}
}

void AVmpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (DisplayLcd->IsValidLowLevelFast()) {
		DisplayLcd->UpdateTexture();
	}
	//DataWheelComponent->rotate(2);
	//RecGainComponent->rotate(2);
	//VolumeComponent->rotate(2);
}

void AVmpc::DataWheelTurn(int increment) {
	mpcInst->getHardware().lock()->getDataWheel().lock()->turn(increment);
}

void AVmpc::ButtonPush(FString label) {
	std::string labelStr(TCHAR_TO_ANSI(*label));
	MLOG("Trying to push button " + labelStr);
	auto button = mpcInst->getHardware().lock()->getButton(labelStr).lock();
	if (button)
		button->push();
}

void AVmpc::ButtonRelease(FString label) {
	std::string labelStr(TCHAR_TO_ANSI(*label));
	auto button = mpcInst->getHardware().lock()->getButton(labelStr).lock();
	if (button)
		button->release();
}

void AVmpc::PadPush(int pad) {
	if (pad >= 1 && pad <= 16) {
		mpcInst->getHardware().lock()->getPad(pad - 1).lock()->push(127);
	}
}

void AVmpc::PadRelease(int pad) {
	if (pad >= 1 && pad <= 16) {
		mpcInst->getHardware().lock()->getPad(pad - 1).lock()->release();
	}
}

void AVmpc::SetRecGain(int value) {
}

void AVmpc::SetVolume(int value) {
}
