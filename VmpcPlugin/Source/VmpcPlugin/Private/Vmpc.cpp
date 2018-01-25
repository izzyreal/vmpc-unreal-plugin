// Fill out your copyright notice in the Description page of Project Settings.

#include "Vmpc.h"
#include "Engine/StaticMesh.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Engine/Texture2D.h"
#include "Runtime/Engine/Classes/Materials/MaterialInstanceDynamic.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Runtime/RHI/Public/RHI.h"
#include "PhysicsEngine/BodySetup.h"

#include <Mpc.hpp>
#include <lcdgui/LayeredScreen.hpp>

#include <VmpcPlugin.h>

#include "VmpcMeshComponent.h"

#include <vector>

AVmpc::AVmpc()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	std::vector<FString> meshNames = { "Display", "After", "BankA", "BankB", "BankC", "BankD", "BarEnd", "BarStart", "Body", "Cursor", "DataWheel", "DisplayCase", "DisplayDock", "Enter", "Erase", "F1", "F2", "F3", "F4", "F5", "F6", "FrontPanel", "FullLevel", "GoTo", "MainScreen", "NextSeq", "NextStep", "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "OpenWindow", "Overdub", "Pads", "Play", "PlayStart", "PrevStep", "Rec", "RecGain", "Shift", "SixteenLevels", "Slider", "Stop", "Tap", "TrackMute", "UndoSeq", "Volume" };

	vmpcAudioComponent = CreateDefaultSubobject<UVmpcAudioComponent>("VmpcAudioComponent");
	vmpcAudioComponent->RegisterComponent();
	vmpcAudioComponent->SetupAttachment(RootComponent);

	for (auto& s : meshNames)
		addMesh(s);
}

void AVmpc::addMesh(FString name) {
	FString fullName = "mpc_" + name;
	fullName += "." + fullName;
	fullName = "StaticMesh'/VmpcPlugin/Mpc/" + fullName + "'";

	if (name == "Display") {
		Display = CreateDefaultSubobject<UVmpcMeshComponent>(*name);
		Display->SetupAttachment(RootComponent);
		ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshBox(*fullName);
		Display->SetStaticMesh(StaticMeshBox.Object);
		Display->RegisterComponent();
	}
	else {
		UVmpcMeshComponent* MeshComponent = CreateDefaultSubobject<UVmpcMeshComponent>(*name);
		MeshComponent->RegisterComponent();
		ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshBox(*fullName);
		MeshComponent->SetStaticMesh(StaticMeshBox.Object);
		MeshComponent->SetupAttachment(RootComponent);
		MeshComponent->setMpc(vmpcAudioComponent);
		MeshComponent->GetBodySetup()->CollisionTraceFlag = ECollisionTraceFlag::CTF_UseComplexAsSimple;
	}
}

void AVmpc::BeginPlay()
{
	Super::BeginPlay();
	vmpcAudioComponent->Start();
}

void AVmpc::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	CreateTexture(false); // don't force new texture (use existing one if found)
	UpdateTexture();
}

void AVmpc::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	CreateTexture(true); // do force new texture
	UpdateTexture();
}

void AVmpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateTexture();
}

void AVmpc::CreateTexture(bool argForceMake)
{
	UE_LOG(LogTemp, Warning, TEXT("---------- Creating Texture! ----------"));

	// check to see if we actually need to make all this from scratch
	if (dtMaterialInstanceDynamic == nullptr || dtTexture == nullptr || argForceMake == true) {

		// dynamic texture properties (hard wired here for now)
		dtBytesPerPixel = 4;
		dtWidth = 248;
		dtHeight = 60;

		// create buffers to collate pixel data into
		dtBufferSize = dtWidth * dtHeight * dtBytesPerPixel;
		dtBufferSizeSqrt = dtWidth * dtBytesPerPixel;
		dtBuffer = new uint8[dtBufferSize]; // this is the data that we Memcpy into the dynamic texture

											// Create dynamic material
		dtMaterialInstanceDynamic = Display->CreateAndSetMaterialInstanceDynamic(0);

		// create dynamic texture
		dtTexture = UTexture2D::CreateTransient(dtWidth, dtHeight);
#if WITH_EDITORONLY_DATA
		dtTexture->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
#endif
		//dtTexture->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;
		dtTexture->CompressionSettings = TextureCompressionSettings::TC_Default;
		dtTexture->Filter = TextureFilter::TF_Nearest;
		dtTexture->SRGB = 0;
		dtTexture->AddToRoot();		// Guarantee no garbage collection by adding it as a root reference
		dtTexture->UpdateResource();	// Update the texture with new variable values.

										// plug the dynamic texture into the dynamic material
		dtMaterialInstanceDynamic->SetTextureParameterValue(FName("DynamicTextureParam"), dtTexture);

		// Create a new texture region with the width and height of our dynamic texture
		dtUpdateTextureRegion = new FUpdateTextureRegion2D(0, 0, 0, 0, dtWidth, dtHeight);
	}
}

void AVmpc::UpdateTexture()
{
	auto ls = vmpcAudioComponent->mpcInst->getLayeredScreen().lock();
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

void AVmpc::UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData)
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
