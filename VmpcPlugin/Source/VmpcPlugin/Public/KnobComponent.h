// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RotatingComponent.h"
#include <hardware/Pot.hpp>
#include "KnobComponent.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API UKnobComponent : public URotatingComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Vmpc|Synth|Components|Audio")
		void SetValue(int value); // 0 - 100

public:
	void setPot(std::weak_ptr<mpc::hardware::Pot> pot);

private:
	std::weak_ptr<mpc::hardware::Pot> pot;
	int value = 0;

};
