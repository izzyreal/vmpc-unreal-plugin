// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Vmpc.h"
#include "VmpcMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API UVmpcMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void triggerPush();

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void triggerRelease();

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void EnableOutline(bool b);

public:
	void setMpc(AVmpc* vmpc);

private:
	int getPadNr(std::string name);

private:
	AVmpc* vmpc;

};
