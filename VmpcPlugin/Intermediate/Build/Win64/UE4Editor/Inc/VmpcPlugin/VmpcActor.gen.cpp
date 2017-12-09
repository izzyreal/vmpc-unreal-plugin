// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/VmpcActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVmpcActor() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_AVmpcActor_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_AVmpcActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	void AVmpcActor::StaticRegisterNativesAVmpcActor()
	{
	}
	UClass* Z_Construct_UClass_AVmpcActor_NoRegister()
	{
		return AVmpcActor::StaticClass();
	}
	UClass* Z_Construct_UClass_AVmpcActor()
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
				{ "IncludePath", "VmpcActor.h" },
				{ "ModuleRelativePath", "Public/VmpcActor.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dtTexture_MetaData[] = {
				{ "ModuleRelativePath", "Public/VmpcActor.h" },
				{ "ToolTip", "dynamic texture" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_dtTexture = { UE4CodeGen_Private::EPropertyClass::Object, "dtTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AVmpcActor, dtTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_dtTexture_MetaData, ARRAY_COUNT(NewProp_dtTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_dtMaterialInstanceDynamic_MetaData[] = {
				{ "ModuleRelativePath", "Public/VmpcActor.h" },
				{ "ToolTip", "dynamic material" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_dtMaterialInstanceDynamic = { UE4CodeGen_Private::EPropertyClass::Object, "dtMaterialInstanceDynamic", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000000000, 1, nullptr, STRUCT_OFFSET(AVmpcActor, dtMaterialInstanceDynamic), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(NewProp_dtMaterialInstanceDynamic_MetaData, ARRAY_COUNT(NewProp_dtMaterialInstanceDynamic_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_testMesh_MetaData[] = {
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/VmpcActor.h" },
				{ "ToolTip", "mesh component" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_testMesh = { UE4CodeGen_Private::EPropertyClass::Object, "testMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080008, 1, nullptr, STRUCT_OFFSET(AVmpcActor, testMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_testMesh_MetaData, ARRAY_COUNT(NewProp_testMesh_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_root_MetaData[] = {
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/VmpcActor.h" },
				{ "ToolTip", "pivot component" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_root = { UE4CodeGen_Private::EPropertyClass::Object, "root", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000080008, 1, nullptr, STRUCT_OFFSET(AVmpcActor, root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(NewProp_root_MetaData, ARRAY_COUNT(NewProp_root_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dtTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_dtMaterialInstanceDynamic,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_testMesh,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_root,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AVmpcActor>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AVmpcActor::StaticClass,
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
	IMPLEMENT_CLASS(AVmpcActor, 2222668674);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVmpcActor(Z_Construct_UClass_AVmpcActor, &AVmpcActor::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("AVmpcActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVmpcActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
