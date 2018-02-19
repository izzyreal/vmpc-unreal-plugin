// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/VmpcAudioComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVmpcAudioComponent() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_UVmpcAudioComponent_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_UVmpcAudioComponent();
	AUDIOMIXER_API UClass* Z_Construct_UClass_USynthComponent();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
// End Cross Module References
	void UVmpcAudioComponent::StaticRegisterNativesUVmpcAudioComponent()
	{
	}
	UClass* Z_Construct_UClass_UVmpcAudioComponent_NoRegister()
	{
		return UVmpcAudioComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UVmpcAudioComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_USynthComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_VmpcPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Synth" },
				{ "HideCategories", "Object ActorComponent Physics Rendering Mobility LOD Trigger PhysicsVolume" },
				{ "IncludePath", "VmpcAudioComponent.h" },
				{ "ModuleRelativePath", "Public/VmpcAudioComponent.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UVmpcAudioComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UVmpcAudioComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00080u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UVmpcAudioComponent, 972556635);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVmpcAudioComponent(Z_Construct_UClass_UVmpcAudioComponent, &UVmpcAudioComponent::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("UVmpcAudioComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVmpcAudioComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
