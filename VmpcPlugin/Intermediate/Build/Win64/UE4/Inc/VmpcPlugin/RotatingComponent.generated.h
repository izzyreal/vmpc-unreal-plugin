// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VMPCPLUGIN_RotatingComponent_generated_h
#error "RotatingComponent.generated.h already included, missing '#pragma once' in RotatingComponent.h"
#endif
#define VMPCPLUGIN_RotatingComponent_generated_h

#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execisInteractable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->isInteractable(); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execisInteractable) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->isInteractable(); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesURotatingComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_URotatingComponent(); \
public: \
	DECLARE_CLASS(URotatingComponent, UVmpcMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(URotatingComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesURotatingComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_URotatingComponent(); \
public: \
	DECLARE_CLASS(URotatingComponent, UVmpcMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(URotatingComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URotatingComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URotatingComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URotatingComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URotatingComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URotatingComponent(URotatingComponent&&); \
	NO_API URotatingComponent(const URotatingComponent&); \
public:


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URotatingComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API URotatingComponent(URotatingComponent&&); \
	NO_API URotatingComponent(const URotatingComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URotatingComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URotatingComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URotatingComponent)


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_PRIVATE_PROPERTY_OFFSET
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_13_PROLOG
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_RPC_WRAPPERS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_INCLASS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_INCLASS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_RotatingComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
