// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VmpcAudioComponent.h"
#include "Vmpc.generated.h"

struct FUpdateTextureRegion2D;

UCLASS()
class VMPCPLUGIN_API AVmpc : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVmpc();

protected:
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

private:
	UVmpcAudioComponent* vmpcAudioComponent;
	void addMesh(FString name);

	// mesh component
	UPROPERTY(VisibleAnywhere, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Display;
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

	void CreateTexture(bool argForceMake);
	
public:
	void UpdateTexture();
	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;

};
