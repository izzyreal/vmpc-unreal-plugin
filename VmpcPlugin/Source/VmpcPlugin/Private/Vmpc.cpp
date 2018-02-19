// Fill out your copyright notice in the Description page of Project Settings.

#include "Vmpc.h"
#include "Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/AssetRegistry/Public/AssetRegistryModule.h"

#include "Components/InstancedStaticMeshComponent.h"

#include "PhysicsEngine/BodySetup.h"


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

#include "VmpcMeshComponent.h"

#include <vector>

const float AVmpc::ANGLE = 5.12253;

AVmpc::AVmpc()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	if (!mpcInst) {
		mpcInst = std::make_shared<mpc::Mpc>();

		//auto sequencer = mpcInst->getSequencer().lock();
		//auto sequence = sequencer->getActiveSequence().lock();
		//sequence->init(2);
		//sequence->setUsed(true);
		//sequence->setName("Unreal-01");
		//sequencer->playFromStart();
	}
	vmpcAudioComponent = CreateDefaultSubobject<UVmpcAudioComponent>("VmpcAudioComponent");
	vmpcAudioComponent->setMpc(mpcInst);
	vmpcAudioComponent->RegisterComponent();
	vmpcAudioComponent->SetupAttachment(RootComponent);

	DataWheelComponent = addRotatable("DataWheel");
	dataWheelObserver = std::make_shared<DataWheelObserver>(DataWheelComponent);
	mpcInst->getHardware().lock()->getDataWheel().lock()->addObserver(dataWheelObserver.get());

	RecGainComponent = addRotatable("RecGain");
	VolumeComponent = addRotatable("Volume");

	addDisplay();

	std::vector<FString> meshNames{ "After", "BankA", "BankB", "BankC", "BankD", "BarEnd", "BarStart", "Body", "Cursor", "DisplayCase", "DisplayDock", "Enter", "Erase", "F1", "F2", "F3", "F4", "F5", "F6", "FrontPanel", "FullLevel", "GoTo", "MainScreen", "NextSeq", "NextStep", "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "OpenWindow", "Overdub", "Pads", "Play", "PlayStart", "PrevStep", "Rec", "Shift", "SixteenLevels", "Slider", "Stop", "Tap", "TrackMute", "UndoSeq" };
	std::vector<FString> nonInteractableMeshNames{ "PivotDataWheel", "PivotRecGain", "PivotVolume", "Display", "Pads", "Cursor", "Body", "FrontPanel", "DisplayCase", "DisplayDock" };
	for (auto& s : meshNames) {
		auto mesh = addMesh(s);
		// TO-DO: add other non-interactables
		for (auto& s1 : nonInteractableMeshNames)
			if (s1.Equals(s))mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	std::vector<FString> invisibleMeshNames{ "CursorLeft", "CursorRight", "CursorUp", "CursorDown", "Pad1", "Pad2", "Pad3", "Pad4", "Pad5", "Pad6", "Pad7", "Pad8", "Pad9", "Pad10", "Pad11", "Pad12", "Pad13", "Pad14", "Pad15", "Pad16" };
	for (auto& s : invisibleMeshNames) {
		auto mesh = addMesh(s);
		mesh->SetRenderInMainPass(false);
	}
}

void AVmpc::addDisplay() {
	FString fullName = "mpc_Display";
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";
	Display = CreateDefaultSubobject<ULcdComponent>("Display");
	Display->setMpc(mpcInst);
	Display->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(*fullName);
	Display->SetStaticMesh(StaticMesh.Object);
	Display->RegisterComponent();
}

UStaticMeshComponent* AVmpc::addMesh(FString name) {
	FString fullName = "mpc_" + name;
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";
	UVmpcMeshComponent* MeshComponent = CreateDefaultSubobject<UVmpcMeshComponent>(*name);
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(*fullName);

	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetStaticMesh(StaticMesh.Object);
	MeshComponent->setMpc(this);
	MeshComponent->RegisterComponent();
	MeshComponent->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;
	return MeshComponent;
}

URotatingComponent* AVmpc::addRotatable(FString name) {
	FString fullName = "mpc_" + name;
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";
	auto rotatableComponent = CreateDefaultSubobject<URotatingComponent>(*name);
	ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(*fullName);

	rotatableComponent->SetupAttachment(RootComponent);
	rotatableComponent->SetStaticMesh(StaticMesh.Object);
	rotatableComponent->setMpc(this);
	rotatableComponent->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;

	rotatableComponent->SetMobility(EComponentMobility::Movable);
	rotatableComponent->RegisterComponent();
	auto pivot = addMesh("Pivot" + name);
	pivot->SetRenderInMainPass(false);
	rotatableComponent->setPivot(pivot);
	return rotatableComponent;
}

void AVmpc::BeginPlay()
{
	Super::BeginPlay();
	vmpcAudioComponent->Start();
}

void AVmpc::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if (Display->IsValidLowLevelFast()) {
		Display->CreateTexture(false);
		Display->UpdateTexture();
	}
}

void AVmpc::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (Display->IsValidLowLevelFast()) {
		Display->CreateTexture(true);
		Display->UpdateTexture();
	}
}

void AVmpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Display->UpdateTexture();
	DataWheelComponent->rotate(2);
	RecGainComponent->rotate(2);
	VolumeComponent->rotate(2);
}

void AVmpc::DataWheelTurn(int increment) {
	mpcInst->getHardware().lock()->getDataWheel().lock()->turn(increment);
}

void AVmpc::ButtonPush(FString label) {
	std::string labelStr(TCHAR_TO_ANSI(*label));
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
