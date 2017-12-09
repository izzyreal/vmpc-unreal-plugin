// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VMPCPLUGIN_VmpcAudioComponent_generated_h
#error "VmpcAudioComponent.generated.h already included, missing '#pragma once' in VmpcAudioComponent.h"
#endif
#define VMPCPLUGIN_VmpcAudioComponent_generated_h

#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execButton) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Button(Z_Param_label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDataWheel) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_increment); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DataWheel(Z_Param_increment); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetFrequency) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FrequencyHz); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetFrequency(Z_Param_FrequencyHz); \
		P_NATIVE_END; \
	}


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execButton) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Button(Z_Param_label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDataWheel) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_increment); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DataWheel(Z_Param_increment); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetFrequency) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_FrequencyHz); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetFrequency(Z_Param_FrequencyHz); \
		P_NATIVE_END; \
	}


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVmpcAudioComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_UVmpcAudioComponent(); \
public: \
	DECLARE_CLASS(UVmpcAudioComponent, USynthComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVmpcAudioComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUVmpcAudioComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_UVmpcAudioComponent(); \
public: \
	DECLARE_CLASS(UVmpcAudioComponent, USynthComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVmpcAudioComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVmpcAudioComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVmpcAudioComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVmpcAudioComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVmpcAudioComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVmpcAudioComponent(UVmpcAudioComponent&&); \
	NO_API UVmpcAudioComponent(const UVmpcAudioComponent&); \
public:


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVmpcAudioComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVmpcAudioComponent(UVmpcAudioComponent&&); \
	NO_API UVmpcAudioComponent(const UVmpcAudioComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVmpcAudioComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVmpcAudioComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVmpcAudioComponent)


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_PRIVATE_PROPERTY_OFFSET
#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_13_PROLOG
#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_RPC_WRAPPERS \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_INCLASS \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_INCLASS_NO_PURE_DECLS \
	plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID plugcomp1_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcAudioComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
