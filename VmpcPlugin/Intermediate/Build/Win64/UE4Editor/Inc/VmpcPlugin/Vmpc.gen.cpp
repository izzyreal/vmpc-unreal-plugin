// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/Vmpc.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVmpc() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_AVmpc_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_AVmpc();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AVmpc::StaticRegisterNativesAVmpc()
	{
	}
	UClass* Z_Construct_UClass_AVmpc_NoRegister()
	{
		return AVmpc::StaticClass();
	}
	UClass* Z_Construct_UClass_AVmpc()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_VmpcPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Vmpc.h" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dtTexture_MetaData[] = {
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_dtTexture = { UE4CodeGen_Private::EPropertyClass::Object, "dtTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AVmpc, dtTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_dtTexture_MetaData, ARRAY_COUNT(NewProp_dtTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dtMaterialInstanceDynamic_MetaData[] = {
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_dtMaterialInstanceDynamic = { UE4CodeGen_Private::EPropertyClass::Object, "dtMaterialInstanceDynamic", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AVmpc, dtMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(NewProp_dtMaterialInstanceDynamic_MetaData, ARRAY_COUNT(NewProp_dtMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Display_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Vmpc" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
				{ "ToolTip", "mesh component" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Display = { UE4CodeGen_Private::EPropertyClass::Object, "Display", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a0009, 1, nullptr, STRUCT_OFFSET(AVmpc, Display), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_Display_MetaData, ARRAY_COUNT(NewProp_Display_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dtTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dtMaterialInstanceDynamic,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Display,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AVmpc>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AVmpc::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(AVmpc, 82786251);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVmpc(Z_Construct_UClass_AVmpc, &AVmpc::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("AVmpc"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVmpc);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif