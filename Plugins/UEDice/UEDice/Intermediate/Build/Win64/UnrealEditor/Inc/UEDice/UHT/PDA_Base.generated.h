// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PDA_Base.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UEDICE_PDA_Base_generated_h
#error "PDA_Base.generated.h already included, missing '#pragma once' in PDA_Base.h"
#endif
#define UEDICE_PDA_Base_generated_h

#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPDA_Base(); \
	friend struct Z_Construct_UClass_UPDA_Base_Statics; \
public: \
	DECLARE_CLASS(UPDA_Base, UPrimaryDataAsset, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEDice"), NO_API) \
	DECLARE_SERIALIZER(UPDA_Base)


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPDA_Base(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPDA_Base(UPDA_Base&&); \
	UPDA_Base(const UPDA_Base&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPDA_Base); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPDA_Base); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPDA_Base) \
	NO_API virtual ~UPDA_Base();


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_12_PROLOG
#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_15_INCLASS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEDICE_API UClass* StaticClass<class UPDA_Base>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
