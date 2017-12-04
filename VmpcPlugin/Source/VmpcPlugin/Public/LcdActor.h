// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LcdActor.generated.h"

struct FUpdateTextureRegion2D;

UCLASS()
class VMPCPLUGIN_API ALcdActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALcdActor();

	// update class instances in the editor if changes are made to their properties
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called after the actors components have been initialized
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Dynamic texture methods
	void CreateTexture(bool argForceMake);
	void UpdateTexture();

	// Magic method to draw texture really quickly
	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);

	// Quick random function for testing
	double rnd();

private:
	// pivot component
	UPROPERTY()
		USceneComponent* root;

	// mesh component
	UPROPERTY()
		UStaticMeshComponent* testMesh;

	// dTex res
	int dtWidth;
	int dtHeight;
	int dtBytesPerPixel;

	// dTex buffer
	uint8 *dtBuffer;
	int dtBufferSize;
	int dtBufferSizeSqrt;

	// dynamic material
	UPROPERTY()
		UMaterialInstanceDynamic* dtMaterialInstanceDynamic;

	// dynamic texture
	UPROPERTY()
		UTexture2D* dtTexture;

	// update texture region magic thingy
	FUpdateTextureRegion2D* dtUpdateTextureRegion;
};
