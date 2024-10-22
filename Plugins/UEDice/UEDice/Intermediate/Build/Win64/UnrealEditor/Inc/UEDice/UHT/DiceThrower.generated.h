// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DiceThrower.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ADiceActor;
class UPDA_Dice;
#ifdef UEDICE_DiceThrower_generated_h
#error "DiceThrower.generated.h already included, missing '#pragma once' in DiceThrower.h"
#endif
#define UEDICE_DiceThrower_generated_h

#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_19_DELEGATE \
static void FOnDieThrown_DelegateWrapper(const FMulticastScriptDelegate& OnDieThrown, ADiceActor* ThrownDie);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_20_DELEGATE \
static void FOnDieSpawned_DelegateWrapper(const FMulticastScriptDelegate& OnDieSpawned, ADiceActor* SpawnedDie);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_21_DELEGATE \
static void FOnDiceCleared_DelegateWrapper(const FMulticastScriptDelegate& OnDiceCleared);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_22_DELEGATE \
static void FOnTotalChanged_DelegateWrapper(const FMulticastScriptDelegate& OnTotalChanged, const FText& NewResult);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnDieClicked); \
	DECLARE_FUNCTION(execOnDiceResult); \
	DECLARE_FUNCTION(execRemoveDice); \
	DECLARE_FUNCTION(execAddDice); \
	DECLARE_FUNCTION(execClearDice); \
	DECLARE_FUNCTION(execRerollDice); \
	DECLARE_FUNCTION(execRerollAll); \
	DECLARE_FUNCTION(execLaunchDie); \
	DECLARE_FUNCTION(execSpawnDice);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADiceThrower(); \
	friend struct Z_Construct_UClass_ADiceThrower_Statics; \
public: \
	DECLARE_CLASS(ADiceThrower, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UEDice"), NO_API) \
	DECLARE_SERIALIZER(ADiceThrower)


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADiceThrower(ADiceThrower&&); \
	ADiceThrower(const ADiceThrower&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADiceThrower); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADiceThrower); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADiceThrower) \
	NO_API virtual ~ADiceThrower();


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_13_PROLOG
#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_INCLASS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEDICE_API UClass* StaticClass<class ADiceThrower>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
