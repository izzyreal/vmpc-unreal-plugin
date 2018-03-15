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

public:
	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void triggerPush();

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void triggerRelease();

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void EnableOutline(bool b);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		virtual bool isInteractable();

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void onMouseDown(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		void onMouseUp(UPrimitiveComponent* ClickedComp, FKey ButtonPressed);

public:
	void setMpc(AVmpc* vmpc);
	void setPushable(bool b);

public:
	bool isPushable();
	bool isPushed();

private:
	int getPadNr(std::string name);

private:
	AVmpc* vmpc;

	bool interactable = false;
	bool pushable = false;

	bool pushed = false;
};
