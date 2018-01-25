// Fill out your copyright notice in the Description page of Project Settings.

#include "VmpcAudioComponent.h"

#include <sequencer/Sequencer.hpp>
#include <sequencer/Sequence.hpp>
#include <audiomidi/AudioMidiServices.hpp>
#include <audio/server/UnrealAudioServer.hpp>

#include <Logger.hpp>
#include <VmpcPlugin.h>

#include <hardware/Hardware.hpp>
#include <hardware/DataWheel.hpp>
#include <hardware/Button.hpp>

void UVmpcAudioComponent::Init(const int32 SampleRate)
{
	NumChannels = 2;
	if (!mpcInst) {
		mpcInst = std::make_shared<mpc::Mpc>();
		mpcInst->init("unreal", SampleRate);
		auto sequencer = mpcInst->getSequencer().lock();
		auto sequence = sequencer->getActiveSequence().lock();
		//sequence->init(2);
		//sequencer->playFromStart();
	}
}

void UVmpcAudioComponent::OnGenerateAudio(float* OutAudio, int32 NumSamples)
{
	auto urserver = mpcInst->getAudioMidiServices().lock()->getUnrealAudioServer();
	urserver->work(OutAudio, NumSamples);
}

void UVmpcAudioComponent::DataWheel(int increment) {
	mpcInst->getHardware().lock()->getDataWheel().lock()->turn(increment);
}

void UVmpcAudioComponent::Button(FString label) {
	std::string labelStr(TCHAR_TO_ANSI(*label));
	auto button = mpcInst->getHardware().lock()->getButton(labelStr).lock();
	if (button)
		button->push();
}

void UVmpcAudioComponent::Activate(bool bReset) {
	moduru::Logger::l.log("Activate\n");
	USynthComponent::Activate(bReset);
}

void UVmpcAudioComponent::Deactivate() {
	moduru::Logger::l.log("Deactivate\n");
	USynthComponent::Deactivate();
}

void UVmpcAudioComponent::OnRegister() {
	moduru::Logger::l.log("OnRegister\n");
	USynthComponent::OnRegister();
}

void UVmpcAudioComponent::OnUnregister() {
	moduru::Logger::l.log("OnUnregister\n");
	USynthComponent::OnUnregister();
}
