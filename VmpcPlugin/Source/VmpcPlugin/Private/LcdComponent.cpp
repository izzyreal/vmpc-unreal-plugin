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
		dtWidth = 360 * scale;
		dtHeight = 360 * scale;

		dtBufferSize = dtWidth * dtHeight * dtBytesPerPixel;
		dtBufferSizeSqrt = dtWidth * dtBytesPerPixel;
		dtBuffer = new uint8[dtBufferSize];

		dtMaterialInstanceDynamic = CreateAndSetMaterialInstanceDynamic(0);

		dtTexture = UTexture2D::CreateTransient(dtWidth, dtHeight);
//#if WITH_EDITORONLY_DATA
		//dtTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
//#endif

		dtTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
		dtTexture->Filter = TextureFilter::TF_Bilinear;
		dtTexture->SRGB = 1;
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
	MLOG("ls is dirty");
	ls->Draw();
	auto lcdPixels = ls->getPixels();

	int pixelCount = dtBufferSize / dtBytesPerPixel;
	auto dirtyRect = ls->getDirtyArea();
	dirtyRect->L -= 1;
	dirtyRect->B += 1;
	
	if (dirtyRect->L < 0) dirtyRect->L = 0;
	if (dirtyRect->R > 248) dirtyRect->R = 248;
	if (dirtyRect->T < 0) dirtyRect->T = 0;
	if (dirtyRect->B > 60) dirtyRect->B = 60;

	int offsetL = 57 * scale;
	int offsetT = 279 * scale;

	for (int i = 0; i < pixelCount; i++) {

		int iBlue = i * 4 + 0;
		int iGreen = i * 4 + 1;
		int iRed = i * 4 + 2;
		int iAlpha = i * 4 + 3;

		int iX = (int)((i % dtWidth));
		int iY = (int)((i / dtWidth));

		if ((iX - offsetL) < (dirtyRect->L * scale) || (iX - offsetL) > (dirtyRect->R * scale) || (iY - offsetT) < (dirtyRect->T * scale) || (iY - offsetT) > (dirtyRect->B * scale)) continue;

		if ((iX - offsetL) >= 0 && (iX - offsetL) < (248 * scale) && (iY - offsetT) >= 0 && (iY - offsetT) < (60 * scale) && lcdPixels->at((iX - offsetL) / scale).at((iY - offsetT) / scale) == true) {
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
	dtUpdateTextureRegion->SrcX = (dirtyRect->L * scale) + offsetL;
	dtUpdateTextureRegion->DestX = (dirtyRect->L * scale) + offsetL;
	dtUpdateTextureRegion->SrcY = (dirtyRect->T * scale) + offsetT;
	dtUpdateTextureRegion->DestY = (dirtyRect->T * scale) + offsetT;
	dtUpdateTextureRegion->Width = dirtyRect->W() * scale;
	dtUpdateTextureRegion->Height = dirtyRect->H() * scale;
	//UpdateMips();
	UpdateTextureRegions(dtTexture, 0, 1, dtUpdateTextureRegion, dtBufferSizeSqrt, (uint32)4, dtBuffer, false);
	dtMaterialInstanceDynamic->SetTextureParameterValue("DynamicTextureParam", dtTexture);
	ls->getDirtyArea()->Clear();
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

void ULcdComponent::AllocateMips() {


}

/*
void ULcdComponent::UpdateMips() {
	auto *pNewTexture = dtTexture;

	int mipsToAdd = 3;// pNewTexture->RequestedMips - 1;
	//int mipsToAdd = pNewTexture->GetNumRequestedMips();
	MLOG("mipsToAdd: " + std::to_string(mipsToAdd));
	MLOG("GetNumMips: " + std::to_string(pNewTexture->GetNumMips()));
	MLOG("GetNumMipsAllowed: " + std::to_string(pNewTexture->GetNumMipsAllowed(true)));
	MLOG("GetNumResidentMips: " + std::to_string(pNewTexture->GetNumResidentMips()));

					  //Declaring buffers here to reduce reallocs
					  //We double buffer mips, using the prior buffer to build the next buffer
	TArray<uint8> _mipRGBAs;
	TArray<uint8> _mipRGBBs;

	//Access source data
	auto* priorData = (const uint8 *)pNewTexture->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	int priorwidth = pNewTexture->PlatformData->Mips[0].SizeX;
	int priorheight = pNewTexture->PlatformData->Mips[0].SizeY;

	while (mipsToAdd > 0)
	{
		auto *mipRGBAs = mipsToAdd & 1 ? &_mipRGBAs : &_mipRGBBs;

		int mipwidth = priorwidth >> 1;
		int mipheight = priorheight >> 1;
		MLOG("mipwidth " + to_string(mipwidth));
		MLOG("mipheight " + to_string(mipheight));

		if ((mipwidth == 0) || (mipheight == 0))
		{
			break;
		}

		mipRGBAs->Reset();
		mipRGBAs->AddUninitialized(mipwidth * mipheight * dtBytesPerPixel);

		int dataPerRow = priorwidth * dtBytesPerPixel;

		//Average out the values
		auto *dataOut = mipRGBAs->GetData();
		for (int y = 0; y < mipheight; y++)
		{
			auto *dataInRow0 = priorData + (dataPerRow * y * 2);
			auto *dataInRow1 = dataInRow0 + dataPerRow;
			for (int x = 0; x < mipwidth; x++)
			{
				int totalB = *dataInRow0++;
				int totalG = *dataInRow0++;
				int totalR = *dataInRow0++;
				int totalA = *dataInRow0++;
				totalB += *dataInRow0++;
				totalG += *dataInRow0++;
				totalR += *dataInRow0++;
				totalA += *dataInRow0++;

				totalB += *dataInRow1++;
				totalG += *dataInRow1++;
				totalR += *dataInRow1++;
				totalA += *dataInRow1++;
				totalB += *dataInRow1++;
				totalG += *dataInRow1++;
				totalR += *dataInRow1++;
				totalA += *dataInRow1++;

				totalB >>= 2;
				totalG >>= 2;
				totalR >>= 2;
				totalA >>= 2;

				*dataOut++ = (uint8)totalB;
				*dataOut++ = (uint8)totalG;
				*dataOut++ = (uint8)totalR;
				*dataOut++ = (uint8)totalA;
			}
			dataInRow0 += priorwidth * 2;
			dataInRow1 += priorwidth * 2;
		}

		// Allocate next mipmap.
		FTexture2DMipMap* Mip = new(pNewTexture->PlatformData->Mips) FTexture2DMipMap();
		Mip->SizeX = mipwidth;
		Mip->SizeY = mipheight;
		Mip->BulkData.Lock(LOCK_READ_WRITE);
		void* mipData = Mip->BulkData.Realloc(mipRGBAs->Num());
		FMemory::Memcpy(mipData, mipRGBAs->GetData(), mipRGBAs->Num());
		Mip->BulkData.Unlock();

		priorData = mipRGBAs->GetData();
		priorwidth = mipwidth;
		priorheight = mipheight;
		--mipsToAdd;
	}

	pNewTexture->PlatformData->Mips[0].BulkData.Unlock();
	pNewTexture->UpdateResource();
}
*/
