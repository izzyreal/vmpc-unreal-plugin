// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/LcdComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLcdComponent() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_ULcdComponent_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_ULcdComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
// End Cross Module References
	void ULcdComponent::StaticRegisterNativesULcdComponent()
	{
	}
	UClass* Z_Construct_UClass_ULcdComponent_NoRegister()
	{
		return ULcdComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_ULcdComponent()
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
				{ "IncludePath", "LcdComponent.h" },
				{ "ModuleRelativePath", "Public/LcdComponent.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dtTexture_MetaData[] = {
				{ "ModuleRelativePath", "Public/LcdComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_dtTexture = { UE4CodeGen_Private::EPropertyClass::Object, "dtTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ULcdComponent, dtTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_dtTexture_MetaData, ARRAY_COUNT(NewProp_dtTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dtMaterialInstanceDynamic_MetaData[] = {
				{ "ModuleRelativePath", "Public/LcdComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_dtMaterialInstanceDynamic = { UE4CodeGen_Private::EPropertyClass::Object, "dtMaterialInstanceDynamic", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(ULcdComponent, dtMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(NewProp_dtMaterialInstanceDynamic_MetaData, ARRAY_COUNT(NewProp_dtMaterialInstanceDynamic_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dtTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dtMaterialInstanceDynamic,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ULcdComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ULcdComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B01080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULcdComponent, 3630905389);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULcdComponent(Z_Construct_UClass_ULcdComponent, &ULcdComponent::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("ULcdComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULcdComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
