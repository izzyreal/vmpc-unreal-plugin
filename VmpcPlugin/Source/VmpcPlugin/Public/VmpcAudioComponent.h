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

	// Sets the oscillator's frequency
	UFUNCTION(BlueprintCallable, Category = "Synth|Components|Audio")
		void SetFrequency(const float FrequencyHz = 440.0f);

	// from SynthComponent
	virtual void Activate(bool bReset = false) override;
	virtual void Deactivate() override;
	virtual void OnRegister() override;
	virtual void OnUnregister() override;


public:
	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void DataWheel(int increment);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void Button(FString label);

protected:
	// A simple oscillator class. Can also generate Saw/Square/Tri/Noise.
	Audio::FOsc Osc;
	//std::shared_ptr<mpc::Mpc> mpc;
};