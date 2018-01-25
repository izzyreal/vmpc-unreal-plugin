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
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_UVmpcMeshComponent_EnableOutline();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_UVmpcMeshComponent_push();
// End Cross Module References
	void UVmpcMeshComponent::StaticRegisterNativesUVmpcMeshComponent()
	{
		UClass* Class = UVmpcMeshComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EnableOutline", (Native)&UVmpcMeshComponent::execEnableOutline },
			{ "push", (Native)&UVmpcMeshComponent::execpush },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UVmpcMeshComponent_EnableOutline()
	{
		struct VmpcMeshComponent_eventEnableOutline_Parms
		{
			bool b;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_b_SetBit = [](void* Obj){ ((VmpcMeshComponent_eventEnableOutline_Parms*)Obj)->b = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_b = { UE4CodeGen_Private::EPropertyClass::Bool, "b", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(VmpcMeshComponent_eventEnableOutline_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_b_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_b,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Interaction" },
				{ "ModuleRelativePath", "Public/VmpcMeshComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVmpcMeshComponent, "EnableOutline", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VmpcMeshComponent_eventEnableOutline_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UVmpcMeshComponent_push()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Interaction" },
				{ "ModuleRelativePath", "Public/VmpcMeshComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVmpcMeshComponent, "push", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
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
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UVmpcMeshComponent_EnableOutline, "EnableOutline" }, // 1980323746
				{ &Z_Construct_UFunction_UVmpcMeshComponent_push, "push" }, // 2633696471
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
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(UVmpcMeshComponent, 1834474412);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVmpcMeshComponent(Z_Construct_UClass_UVmpcMeshComponent, &UVmpcMeshComponent::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("UVmpcMeshComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVmpcMeshComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
