// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef VMPCPLUGIN_Vmpc_generated_h
#error "Vmpc.generated.h already included, missing '#pragma once' in Vmpc.h"
#endif
#define VMPCPLUGIN_Vmpc_generated_h

#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->OnHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	}


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAVmpc(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_AVmpc(); \
public: \
	DECLARE_CLASS(AVmpc, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVmpc) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAVmpc(); \
	friend VMPCPLUGIN_API class UClass* Z_Construct_UClass_AVmpc(); \
public: \
	DECLARE_CLASS(AVmpc, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/VmpcPlugin"), NO_API) \
	DECLARE_SERIALIZER(AVmpc) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_STANDARD_CONSTRUCTORS \
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


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AVmpc(AVmpc&&); \
	NO_API AVmpc(const AVmpc&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AVmpc); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AVmpc); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AVmpc)


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Display() { return STRUCT_OFFSET(AVmpc, Display); } \
	FORCEINLINE static uint32 __PPO__dtMaterialInstanceDynamic() { return STRUCT_OFFSET(AVmpc, dtMaterialInstanceDynamic); } \
	FORCEINLINE static uint32 __PPO__dtTexture() { return STRUCT_OFFSET(AVmpc, dtTexture); }


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_12_PROLOG
#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_RPC_WRAPPERS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_INCLASS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_PRIVATE_PROPERTY_OFFSET \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_INCLASS_NO_PURE_DECLS \
	vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID vrmpc_Plugins_VmpcPlugin_Source_VmpcPlugin_Public_Vmpc_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
