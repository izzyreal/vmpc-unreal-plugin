// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"

#include <Mpc.hpp>
#include "LcdComponent.generated.h"

/**
 * 
 */
UCLASS()
class VMPCPLUGIN_API ULcdComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	std::weak_ptr<mpc::Mpc> mpc;
	int offset;
	int dtWidth;
	int dtHeight;
	int dtBytesPerPixel;
	uint8 *dtBuffer;
	int dtBufferSize;
	int dtBufferSizeSqrt;

	UPROPERTY()
		UMaterialInstanceDynamic* dtMaterialInstanceDynamic;

	UPROPERTY()
		UTexture2D* dtTexture;

	FUpdateTextureRegion2D* dtUpdateTextureRegion;

public:
	void CreateTexture(bool argForceMake);
	void UpdateTexture();
	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);
	void setMpc(std::weak_ptr<mpc::Mpc> mpc);
	
};
