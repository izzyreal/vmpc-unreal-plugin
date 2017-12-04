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

	moduru::Logger::l.log("Init\n");
	NumChannels = 2;
	/*
	if (!mpc) {
		mpc = std::make_shared<mpc::Mpc>();
		mpc->init();
		auto sequencer = mpc->getSequencer().lock();
		auto sequence = sequencer->getActiveSequence().lock();
		sequence->init(2);
		sequencer->playFromStart();
	}
	*/
	// Initialize the DSP objects
	Osc.Init(SampleRate);
	Osc.SetFrequency(440.0f);
	Osc.Start();
}

void UVmpcAudioComponent::OnGenerateAudio(float* OutAudio, int32 NumSamples)
{
	// Perform DSP operations here.
	//for (int32 Sample = 0; Sample < NumSamples; Sample += 2) {	OutAudio[Sample] = Osc.Generate(); }
	auto urserver = mpcInstance->getAudioMidiServices().lock()->getUnrealAudioServer();
	urserver->work(OutAudio, NumSamples);
}

void UVmpcAudioComponent::DataWheel(int increment) {
	mpcInstance->getHardware().lock()->getDataWheel().lock()->turn(increment);
}

void UVmpcAudioComponent::Button(FString label) {
	std::string labelStr(TCHAR_TO_ANSI(*label));
	mpcInstance->getHardware().lock()->getButton(labelStr).lock()->push();
}

void UVmpcAudioComponent::SetFrequency(const float InFrequencyHz)
{
	// Use this protected base class method to push a lambda function which will safely execute in the audio render thread.
	SynthCommand([this, InFrequencyHz]()
	{
		Osc.SetFrequency(InFrequencyHz);
		Osc.Update();
	});
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
