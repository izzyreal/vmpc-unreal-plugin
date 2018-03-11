// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/NonVRPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNonVRPawn() {}
// Cross Module References
	VMPCPLUGIN_API UClass* Z_Construct_UClass_ANonVRPawn_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_ANonVRPawn();
	ENGINE_API UClass* Z_Construct_UClass_ADefaultPawn();
	UPackage* Z_Construct_UPackage__Script_VmpcPlugin();
// End Cross Module References
	void ANonVRPawn::StaticRegisterNativesANonVRPawn()
	{
	}
	UClass* Z_Construct_UClass_ANonVRPawn_NoRegister()
	{
		return ANonVRPawn::StaticClass();
	}
	UClass* Z_Construct_UClass_ANonVRPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_ADefaultPawn,
				(UObject* (*)())Z_Construct_UPackage__Script_VmpcPlugin,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "NonVRPawn.h" },
				{ "ModuleRelativePath", "Public/NonVRPawn.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ANonVRPawn>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ANonVRPawn::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
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
	IMPLEMENT_CLASS(ANonVRPawn, 3357666495);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ANonVRPawn(Z_Construct_UClass_ANonVRPawn, &ANonVRPawn::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("ANonVRPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANonVRPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
