// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "StringUtils.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UEDICE_StringUtils_generated_h
#error "StringUtils.generated.h already included, missing '#pragma once' in StringUtils.h"
#endif
#define UEDICE_StringUtils_generated_h

#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execPadInteger);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUStringUtils(); \
	friend struct Z_Construct_UClass_UStringUtils_Statics; \
public: \
	DECLARE_CLASS(UStringUtils, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEDice"), NO_API) \
	DECLARE_SERIALIZER(UStringUtils)


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UStringUtils(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UStringUtils(UStringUtils&&); \
	UStringUtils(const UStringUtils&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UStringUtils); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStringUtils); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UStringUtils) \
	NO_API virtual ~UStringUtils();


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_12_PROLOG
#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_INCLASS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEDICE_API UClass* StaticClass<class UStringUtils>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
