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
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_AVmpc_ButtonPush();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_AVmpc_ButtonRelease();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_AVmpc_DataWheelTurn();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_AVmpc_PadPush();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_AVmpc_PadRelease();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_URotatingComponent_NoRegister();
	VMPCPLUGIN_API UClass* Z_Construct_UClass_ULcdComponent_NoRegister();
// End Cross Module References
	void AVmpc::StaticRegisterNativesAVmpc()
	{
		UClass* Class = AVmpc::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ButtonPush", (Native)&AVmpc::execButtonPush },
			{ "ButtonRelease", (Native)&AVmpc::execButtonRelease },
			{ "DataWheelTurn", (Native)&AVmpc::execDataWheelTurn },
			{ "PadPush", (Native)&AVmpc::execPadPush },
			{ "PadRelease", (Native)&AVmpc::execPadRelease },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AVmpc_ButtonPush()
	{
		struct Vmpc_eventButtonPush_Parms
		{
			FString label;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_label = { UE4CodeGen_Private::EPropertyClass::Str, "label", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Vmpc_eventButtonPush_Parms, label), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_label,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AVmpc, "ButtonPush", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Vmpc_eventButtonPush_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVmpc_ButtonRelease()
	{
		struct Vmpc_eventButtonRelease_Parms
		{
			FString label;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_label = { UE4CodeGen_Private::EPropertyClass::Str, "label", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Vmpc_eventButtonRelease_Parms, label), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_label,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AVmpc, "ButtonRelease", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Vmpc_eventButtonRelease_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVmpc_DataWheelTurn()
	{
		struct Vmpc_eventDataWheelTurn_Parms
		{
			int32 increment;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_increment = { UE4CodeGen_Private::EPropertyClass::Int, "increment", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Vmpc_eventDataWheelTurn_Parms, increment), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_increment,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AVmpc, "DataWheelTurn", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Vmpc_eventDataWheelTurn_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVmpc_PadPush()
	{
		struct Vmpc_eventPadPush_Parms
		{
			int32 pad;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_pad = { UE4CodeGen_Private::EPropertyClass::Int, "pad", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Vmpc_eventPadPush_Parms, pad), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pad,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AVmpc, "PadPush", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Vmpc_eventPadPush_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AVmpc_PadRelease()
	{
		struct Vmpc_eventPadRelease_Parms
		{
			int32 pad;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_pad = { UE4CodeGen_Private::EPropertyClass::Int, "pad", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Vmpc_eventPadRelease_Parms, pad), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pad,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AVmpc, "PadRelease", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(Vmpc_eventPadRelease_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
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
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AVmpc_ButtonPush, "ButtonPush" }, // 2034511730
				{ &Z_Construct_UFunction_AVmpc_ButtonRelease, "ButtonRelease" }, // 3583582538
				{ &Z_Construct_UFunction_AVmpc_DataWheelTurn, "DataWheelTurn" }, // 2839694487
				{ &Z_Construct_UFunction_AVmpc_PadPush, "PadPush" }, // 895416283
				{ &Z_Construct_UFunction_AVmpc_PadRelease, "PadRelease" }, // 3952745916
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "Vmpc.h" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VolumeComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Vmpc" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_VolumeComponent = { UE4CodeGen_Private::EPropertyClass::Object, "VolumeComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AVmpc, VolumeComponent), Z_Construct_UClass_URotatingComponent_NoRegister, METADATA_PARAMS(NewProp_VolumeComponent_MetaData, ARRAY_COUNT(NewProp_VolumeComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RecGainComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Vmpc" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RecGainComponent = { UE4CodeGen_Private::EPropertyClass::Object, "RecGainComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AVmpc, RecGainComponent), Z_Construct_UClass_URotatingComponent_NoRegister, METADATA_PARAMS(NewProp_RecGainComponent_MetaData, ARRAY_COUNT(NewProp_RecGainComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DataWheelComponent_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Vmpc" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DataWheelComponent = { UE4CodeGen_Private::EPropertyClass::Object, "DataWheelComponent", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AVmpc, DataWheelComponent), Z_Construct_UClass_URotatingComponent_NoRegister, METADATA_PARAMS(NewProp_DataWheelComponent_MetaData, ARRAY_COUNT(NewProp_DataWheelComponent_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Display_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Vmpc" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "Public/Vmpc.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Display = { UE4CodeGen_Private::EPropertyClass::Object, "Display", RF_Public|RF_Transient|RF_MarkAsNative, 0x00100000000a0009, 1, nullptr, STRUCT_OFFSET(AVmpc, Display), Z_Construct_UClass_ULcdComponent_NoRegister, METADATA_PARAMS(NewProp_Display_MetaData, ARRAY_COUNT(NewProp_Display_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_VolumeComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RecGainComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_DataWheelComponent,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Display,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AVmpc>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AVmpc::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AVmpc, 2276386296);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AVmpc(Z_Construct_UClass_AVmpc, &AVmpc::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("AVmpc"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVmpc);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
