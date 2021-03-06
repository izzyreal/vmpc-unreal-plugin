// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VmpcAudioComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimSequence.h"
#include <Mpc.hpp>
#include "DataWheelObserver.h"
#include "Vmpc.generated.h"

struct FUpdateTextureRegion2D;
class ULcdComponent;
class URotatingComponent;
class UKnobComponent;
class UVmpcMeshComponent;

UCLASS()

class VMPCPLUGIN_API AVmpc : public AActor
{
	GENERATED_BODY()

private:
	std::shared_ptr<DataWheelObserver> dataWheelObserver;

public:
	static const float ANGLE;

public:
	AVmpc();

public:
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		ULcdComponent* DisplayLcd;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		URotatingComponent* DataWheelComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UKnobComponent* RecGainComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UKnobComponent* VolumeComponent;

	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UVmpcMeshComponent* BodyComponent;

protected:
	void BeginPlay() override;
	void PostInitializeComponents() override;

private:
	UVmpcAudioComponent* vmpcAudioComponent;
	UVmpcMeshComponent* addMesh(FString name);
	URotatingComponent* addRotatable(FString name, bool knob);
	void addDisplay();
	bool IsWorldValid();

public:	
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

public:
	std::shared_ptr<mpc::Mpc> mpcInst;

public:
	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void DataWheelTurn(int increment);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void ButtonPush(FString label);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void ButtonRelease(FString label);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void PadPush(int pad);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void PadRelease(int pad);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void SetRecGain(int value); // 0 - 100

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void SetVolume(int value); // 0 - 100

};
