// Fill out your copyright notice in the Description page of Project Settings.

#include "LcdComponent.h"
#include "Engine/Texture2D.h"
#include "Runtime/RHI/Public/RHI.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"

void ULcdComponent::setMpc(std::weak_ptr<mpc::Mpc> mpc) {
	this->mpc = mpc;
}

void ULcdComponent::CreateTexture(bool argForceMake)
{
	UE_LOG(LogTemp, Warning, TEXT("---------- Creating Texture! ----------"));

	if (dtMaterialInstanceDynamic == nullptr || dtTexture == nullptr || argForceMake == true) {

		dtBytesPerPixel = 4;
		dtWidth = 248;
		dtHeight = 60;

		dtBufferSize = dtWidth * dtHeight * dtBytesPerPixel;
		dtBufferSizeSqrt = dtWidth * dtBytesPerPixel;
		dtBuffer = new uint8[dtBufferSize];

		dtMaterialInstanceDynamic = CreateAndSetMaterialInstanceDynamic(0);

		dtTexture = UTexture2D::CreateTransient(dtWidth, dtHeight);
#if WITH_EDITORONLY_DATA
		dtTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
#endif
		dtTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
		dtTexture->Filter = TextureFilter::TF_Nearest;
		dtTexture->SRGB = 0;
		dtTexture->AddToRoot();
		dtTexture->UpdateResource();
		dtMaterialInstanceDynamic->SetTextureParameterValue(FName("DynamicTextureParam"), dtTexture);
		dtUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, dtWidth, dtHeight);
	}
}

void ULcdComponent::UpdateTexture()
{
	if (!mpc.lock()) return;
	auto ls = mpc.lock()->getLayeredScreen().lock();
	if (!ls->IsDirty()) return;
	ls->Draw();
	auto lcdPixels = ls->getPixels();

	int pixelCount = dtBufferSize / dtBytesPerPixel;
	auto da = ls->getDirtyArea();
	da->L -= 1;
	da->B += 1;
	if (da->L < 0) da->L = 0;
	if (da->R > 248) da->R = 248;
	if (da->T < 0) da->T = 0;
	if (da->B > 60) da->B = 60;

	for (int i = 0; i < pixelCount; i++) {

		int iBlue = i * 4 + 0;
		int iGreen = i * 4 + 1;
		int iRed = i * 4 + 2;
		int iAlpha = i * 4 + 3;

		int iX = (int)((i % dtWidth));
		int iY = (int)((i / dtWidth));

		if (iX < da->L || iX > da->R || iY < da->T || iY > da->B) continue;

		if (iX < 248 && iY < 60 && lcdPixels->at(iX).at(iY) == true) {
			dtBuffer[iRed] = 86;
			dtBuffer[iGreen] = 61;
			dtBuffer[iBlue] = 145;
			dtBuffer[iAlpha] = 255;
		}
		else {
			dtBuffer[iRed] = 170;
			dtBuffer[iGreen] = 248;
			dtBuffer[iBlue] = 218;
			dtBuffer[iAlpha] = 255;
		}
	}
	dtUpdateTextureRegion->SrcX = da->L;
	dtUpdateTextureRegion->DestX = da->L;
	dtUpdateTextureRegion->SrcY = da->T;
	dtUpdateTextureRegion->DestY = da->T;
	dtUpdateTextureRegion->Width = da->W();
	dtUpdateTextureRegion->Height = da->H();
	ls->getDirtyArea()->Clear();
	UpdateTextureRegions(dtTexture, 0, 1, dtUpdateTextureRegion, dtBufferSizeSqrt, (uint32)4, dtBuffer, false);
	dtMaterialInstanceDynamic->SetTextureParameterValue("DynamicTextureParam", dtTexture);
}

void ULcdComponent::UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData)
{
	if (Texture && Texture->Resource)
	{
		struct FUpdateTextureRegionsData
		{
			FTexture2DResource* Texture2DResource;
			int32 MipIndex;
			uint32 NumRegions;
			FUpdateTextureRegion2D* Regions;
			uint32 SrcPitch;
			uint32 SrcBpp;
			uint8* SrcData;
		};

		FUpdateTextureRegionsData* RegionData = new FUpdateTextureRegionsData;

		RegionData->Texture2DResource = (FTexture2DResource*)Texture->Resource;
		RegionData->MipIndex = MipIndex;
		RegionData->NumRegions = NumRegions;
		RegionData->Regions = Regions;
		RegionData->SrcPitch = SrcPitch;
		RegionData->SrcBpp = SrcBpp;
		RegionData->SrcData = SrcData;

		ENQUEUE_UNIQUE_RENDER_COMMAND_TWOPARAMETER(
			UpdateTextureRegionsData,
			FUpdateTextureRegionsData*, RegionData, RegionData,
			bool, bFreeData, bFreeData,
			{
				for (uint32 RegionIndex = 0; RegionIndex < RegionData->NumRegions; ++RegionIndex)
				{
					int32 CurrentFirstMip = RegionData->Texture2DResource->GetCurrentFirstMip();
					if (RegionData->MipIndex >= CurrentFirstMip)
					{
						RHIUpdateTexture2D(
							RegionData->Texture2DResource->GetTexture2DRHI(),
							RegionData->MipIndex - CurrentFirstMip,
							RegionData->Regions[RegionIndex],
							RegionData->SrcPitch,
							RegionData->SrcData
							+ RegionData->Regions[RegionIndex].SrcY * RegionData->SrcPitch
							+ RegionData->Regions[RegionIndex].SrcX * RegionData->SrcBpp
						);
					}
				}

		if (bFreeData)
		{
			FMemory::Free(RegionData->Regions);
			FMemory::Free(RegionData->SrcData);
		}
		delete RegionData;
			});
	}
}