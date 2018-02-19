// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/RotatingComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRotatingComponent() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_URotatingComponent_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_URotatingComponent();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_UVmpcMeshComponent();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
// End Cross Module References
	void URotatingComponent::StaticRegisterNativesURotatingComponent()
	{
	}
	UClass* Z_Construct_UClass_URotatingComponent_NoRegister()
	{
		return URotatingComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_URotatingComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UVmpcMeshComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_VmpcPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Object Activation Components|Activation Trigger" },
				{ "IncludePath", "RotatingComponent.h" },
				{ "ModuleRelativePath", "Public/RotatingComponent.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<URotatingComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&URotatingComponent::StaticClass,
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
	IMPLEMENT_CLASS(URotatingComponent, 157398916);
	static FCompiledInDefer Z_CompiledInDefer_UClass_URotatingComponent(Z_Construct_UClass_URotatingComponent, &URotatingComponent::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("URotatingComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(URotatingComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
