// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "VmpcMeshComponent.h"
#include "RotatingComponent.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API URotatingComponent : public UVmpcMeshComponent
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Vmpc|Interaction")
		bool isInteractable() override { return true; };

private:
	UStaticMeshComponent * pivot;
	int currentAngle = 0;

public:
	void setPivot(UStaticMeshComponent* pivot);
	void rotate(int degrees);
	
private:
	std::vector<FVector> newLocations;
	std::vector<FRotator> newRotations;
	
protected:
	virtual void BeginPlay() override;

private:
	void rotateAroundPoint(UStaticMeshComponent* comp, float angle, FVector pointToRotAround, FVector axisToRotAround, bool store);
};
