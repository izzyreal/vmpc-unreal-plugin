// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VMPCPLUGIN_Vmpc_generated_h
#error "Vmpc.generated.h already included, missing '#pragma once' in Vmpc.h"
#endif
#define VMPCPLUGIN_Vmpc_generated_h

#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPadRelease) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_pad); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PadRelease(Z_Param_pad); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPadPush) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_pad); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PadPush(Z_Param_pad); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execButtonRelease) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ButtonRelease(Z_Param_label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execButtonPush) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ButtonPush(Z_Param_label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDataWheelTurn) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_increment); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DataWheelTurn(Z_Param_increment); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPadRelease) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_pad); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PadRelease(Z_Param_pad); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPadPush) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_pad); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PadPush(Z_Param_pad); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execButtonRelease) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ButtonRelease(Z_Param_label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execButtonPush) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_label); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ButtonPush(Z_Param_label); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDataWheelTurn) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_increment); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DataWheelTurn(Z_Param_increment); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVmpc(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_AVmpc(); \
public: \
	DECLARE_CLASS(AVmpc, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVmpc) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAVmpc(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_AVmpc(); \
public: \
	DECLARE_CLASS(AVmpc, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVmpc) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AVmpc(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AVmpc) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVmpc); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVmpc); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVmpc(AVmpc&&); \
	NO_API AVmpc(const AVmpc&); \
public:


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVmpc(AVmpc&&); \
	NO_API AVmpc(const AVmpc&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVmpc); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVmpc); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVmpc)


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_PRIVATE_PROPERTY_OFFSET
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_18_PROLOG
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_RPC_WRAPPERS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_INCLASS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_INCLASS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
