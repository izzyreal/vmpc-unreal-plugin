// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VMPCPLUGIN_LcdComponent_generated_h
#error "LcdComponent.generated.h already included, missing '#pragma once' in LcdComponent.h"
#endif
#define VMPCPLUGIN_LcdComponent_generated_h

#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_RPC_WRAPPERS
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesULcdComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_ULcdComponent(); \
public: \
	DECLARE_CLASS(ULcdComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(ULcdComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_INCLASS \
private: \
	static void StaticRegisterNativesULcdComponent(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_ULcdComponent(); \
public: \
	DECLARE_CLASS(ULcdComponent, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(ULcdComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULcdComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULcdComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcdComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcdComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULcdComponent(ULcdComponent&&); \
	NO_API ULcdComponent(const ULcdComponent&); \
public:


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ULcdComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ULcdComponent(ULcdComponent&&); \
	NO_API ULcdComponent(const ULcdComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ULcdComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ULcdComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ULcdComponent)


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__dtMaterialInstanceDynamic() { return STRUCT_OFFSET(ULcdComponent, dtMaterialInstanceDynamic); } \
	FORCEINLINE static uint32 __PPO__dtTexture() { return STRUCT_OFFSET(ULcdComponent, dtTexture); }


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_14_PROLOG
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_RPC_WRAPPERS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_INCLASS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_INCLASS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_LcdComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
