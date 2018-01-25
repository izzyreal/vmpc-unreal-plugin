// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/VmpcMeshComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVmpcMeshComponent() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_UVmpcMeshComponent_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_UVmpcMeshComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
// End Cross Module References
	void UVmpcMeshComponent::StaticRegisterNativesUVmpcMeshComponent()
	{
	}
	UClass* Z_Construct_UClass_UVmpcMeshComponent_NoRegister()
	{
		return UVmpcMeshComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UVmpcMeshComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_VmpcPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Object Activation Components|Activation Trigger" },
				{ "IncludePath", "VmpcMeshComponent.h" },
				{ "ModuleRelativePath", "Public/VmpcMeshComponent.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UVmpcMeshComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UVmpcMeshComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B01080u,
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
	IMPLEMENT_CLASS(UVmpcMeshComponent, 3419671354);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVmpcMeshComponent(Z_Construct_UClass_UVmpcMeshComponent, &UVmpcMeshComponent::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("UVmpcMeshComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVmpcMeshComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
