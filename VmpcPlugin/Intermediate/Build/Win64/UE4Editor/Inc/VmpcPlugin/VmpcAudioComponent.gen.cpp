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
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_UVmpcAudioComponent_Button();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_UVmpcAudioComponent_DataWheel();
	VMPCPLUGIN_API UFunction* Z_Construct_UFunction_UVmpcAudioComponent_SetFrequency();
// End Cross Module References
	void UVmpcAudioComponent::StaticRegisterNativesUVmpcAudioComponent()
	{
		UClass* Class = UVmpcAudioComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Button", (Native)&UVmpcAudioComponent::execButton },
			{ "DataWheel", (Native)&UVmpcAudioComponent::execDataWheel },
			{ "SetFrequency", (Native)&UVmpcAudioComponent::execSetFrequency },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UVmpcAudioComponent_Button()
	{
		struct VmpcAudioComponent_eventButton_Parms
		{
			FString label;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_label = { UE4CodeGen_Private::EPropertyClass::Str, "label", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VmpcAudioComponent_eventButton_Parms, label), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_label,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/VmpcAudioComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVmpcAudioComponent, "Button", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VmpcAudioComponent_eventButton_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UVmpcAudioComponent_DataWheel()
	{
		struct VmpcAudioComponent_eventDataWheel_Parms
		{
			int32 increment;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_increment = { UE4CodeGen_Private::EPropertyClass::Int, "increment", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(VmpcAudioComponent_eventDataWheel_Parms, increment), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_increment,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Vmpc|Synth|Components|Audio" },
				{ "ModuleRelativePath", "Public/VmpcAudioComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVmpcAudioComponent, "DataWheel", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(VmpcAudioComponent_eventDataWheel_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UVmpcAudioComponent_SetFrequency()
	{
		struct VmpcAudioComponent_eventSetFrequency_Parms
		{
			float FrequencyHz;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FrequencyHz_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FrequencyHz = { UE4CodeGen_Private::EPropertyClass::Float, "FrequencyHz", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000082, 1, nullptr, STRUCT_OFFSET(VmpcAudioComponent_eventSetFrequency_Parms, FrequencyHz), METADATA_PARAMS(NewProp_FrequencyHz_MetaData, ARRAY_COUNT(NewProp_FrequencyHz_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FrequencyHz,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Synth|Components|Audio" },
				{ "CPP_Default_FrequencyHz", "440.000000" },
				{ "ModuleRelativePath", "Public/VmpcAudioComponent.h" },
				{ "ToolTip", "Sets the oscillator's frequency" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UVmpcAudioComponent, "SetFrequency", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04040401, sizeof(VmpcAudioComponent_eventSetFrequency_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
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
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UVmpcAudioComponent_Button, "Button" }, // 2190278832
				{ &Z_Construct_UFunction_UVmpcAudioComponent_DataWheel, "DataWheel" }, // 28274145
				{ &Z_Construct_UFunction_UVmpcAudioComponent_SetFrequency, "SetFrequency" }, // 355562352
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
	IMPLEMENT_CLASS(UVmpcAudioComponent, 1785539255);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UVmpcAudioComponent(Z_Construct_UClass_UVmpcAudioComponent, &UVmpcAudioComponent::StaticClass, TEXT("/Script/VmpcPlugin"), TEXT("UVmpcAudioComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVmpcAudioComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
