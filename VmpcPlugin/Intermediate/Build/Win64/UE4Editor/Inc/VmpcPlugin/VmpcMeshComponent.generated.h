// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VMPCPLUGIN_VmpcMeshComponent_generated_h
#error "VmpcMeshComponent.generated.h already included, missing '#pragma once' in VmpcMeshComponent.h"
#endif
#define VMPCPLUGIN_VmpcMeshComponent_generated_h

#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEnableOutline) \
	{ \
		P_GET_UBOOL(Z_Param_b); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EnableOutline(Z_Param_b); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execpush) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->push(); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEnableOutline) \
	{ \
		P_GET_UBOOL(Z_Param_b); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EnableOutline(Z_Param_b); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execpush) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->push(); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUVmpcMeshComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_UVmpcMeshComponent(); \
public: \
	DECLARE_CLASS(UVmpcMeshComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVmpcMeshComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_INCLASS \
private: \
	static void StaticRegisterNativesUVmpcMeshComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_UVmpcMeshComponent(); \
public: \
	DECLARE_CLASS(UVmpcMeshComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(UVmpcMeshComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVmpcMeshComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVmpcMeshComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVmpcMeshComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVmpcMeshComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVmpcMeshComponent(UVmpcMeshComponent&&); \
	NO_API UVmpcMeshComponent(const UVmpcMeshComponent&); \
public:


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UVmpcMeshComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UVmpcMeshComponent(UVmpcMeshComponent&&); \
	NO_API UVmpcMeshComponent(const UVmpcMeshComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UVmpcMeshComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UVmpcMeshComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UVmpcMeshComponent)


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_PRIVATE_PROPERTY_OFFSET
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_14_PROLOG
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_RPC_WRAPPERS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_INCLASS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_INCLASS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_VmpcMeshComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
