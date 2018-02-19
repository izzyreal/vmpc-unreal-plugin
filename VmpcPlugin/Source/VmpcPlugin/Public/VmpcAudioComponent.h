// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SynthComponent.h"
#include "DSP/Osc.h"
#include <Mpc.hpp>

#include "VmpcAudioComponent.generated.h"

UCLASS(ClassGroup = Synth, meta = (BlueprintSpawnableComponent))
class VMPCPLUGIN_API UVmpcAudioComponent : public USynthComponent
{
	GENERATED_BODY()

	// Called when synth is created
	virtual void Init(const int32 SampleRate) override;

	// Called to generate more audio
	virtual void OnGenerateAudio(float* OutAudio, int32 NumSamples) override;
	
private:
	std::weak_ptr<mpc::Mpc> mpc;

public:
	void setMpc(std::weak_ptr<mpc::Mpc> mpc);
};