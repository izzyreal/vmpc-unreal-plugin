// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include <Mpc.hpp>
#include "VmpcAudioComponent.h"
#include "VmpcMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API UVmpcMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void push();

		UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void EnableOutline(bool b);

public:
	void setMpc(UVmpcAudioComponent* mpc);


private:
	UVmpcAudioComponent* mpc;
};
