// Fill out your copyright notice in the Description page of Project Settings.

#include "VmpcAudioComponent.h"

#include <audiomidi/AudioMidiServices.hpp>
#include <audio/server/UnrealAudioServer.hpp>

#include <Logger.hpp>
#include <VmpcPlugin.h>

void UVmpcAudioComponent::setMpc(std::weak_ptr<mpc::Mpc> mpc) {
	this->mpc = mpc;
}

void UVmpcAudioComponent::Init(const int32 SampleRate)
{
	NumChannels = 2;
	MLOG("Setting sample rate to " + std::to_string(SampleRate));
	mpc.lock()->init("unreal", SampleRate);
}

void UVmpcAudioComponent::OnGenerateAudio(float* OutAudio, int32 NumSamples)
{
	auto ams = mpc.lock()->getAudioMidiServices().lock();
	if (ams->isDisabled()) return;
	auto urserver = ams->getUnrealAudioServer();
	if (urserver->getBufferSize() != (NumSamples / 2)) {
		MLOG("Resizing buffers from " + to_string(urserver->getBufferSize()) + " to " + to_string(NumSamples));
		urserver->resizeBuffers(NumSamples / 2);
	}
	urserver->work(OutAudio, NumSamples);
}
