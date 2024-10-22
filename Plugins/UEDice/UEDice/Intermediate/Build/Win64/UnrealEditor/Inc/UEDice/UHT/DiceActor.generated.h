// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DiceActor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class ADiceActor;
class UPrimitiveComponent;
enum class EDieState : uint8;
struct FHitResult;
struct FKey;
#ifdef UEDICE_DiceActor_generated_h
#error "DiceActor.generated.h already included, missing '#pragma once' in DiceActor.h"
#endif
#define UEDICE_DiceActor_generated_h

#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_29_DELEGATE \
static void FOnDieResult_DelegateWrapper(const FMulticastScriptDelegate& OnDieResult, ADiceActor* Die, const FText& Result);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_30_DELEGATE \
static void FOnDieStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnDieStateChanged, ADiceActor* Die, EDieState NewDieState);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_31_DELEGATE \
static void FOnDieHover_DelegateWrapper(const FMulticastScriptDelegate& OnDieHover, ADiceActor* Die);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_32_DELEGATE \
static void FOnDieHoverEnd_DelegateWrapper(const FMulticastScriptDelegate& OnDieHoverEnd, ADiceActor* Die);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_33_DELEGATE \
static void FOnDieClicked_DelegateWrapper(const FMulticastScriptDelegate& OnDieClicked, ADiceActor* Die);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execHandleOnHit); \
	DECLARE_FUNCTION(execHandlePhysicsSleep); \
	DECLARE_FUNCTION(execInitializeDice); \
	DECLARE_FUNCTION(execHandleOnClicked); \
	DECLARE_FUNCTION(execHandleEndCursorOver); \
	DECLARE_FUNCTION(execHandleBeginCursorOver); \
	DECLARE_FUNCTION(execSetDieState); \
	DECLARE_FUNCTION(execGetDieState);


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesADiceActor(); \
	friend struct Z_Construct_UClass_ADiceActor_Statics; \
public: \
	DECLARE_CLASS(ADiceActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/UEDice"), NO_API) \
	DECLARE_SERIALIZER(ADiceActor)


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	ADiceActor(ADiceActor&&); \
	ADiceActor(const ADiceActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADiceActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADiceActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADiceActor) \
	NO_API virtual ~ADiceActor();


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_23_PROLOG
#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_INCLASS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEDICE_API UClass* StaticClass<class ADiceActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h


#define FOREACH_ENUM_EDIESTATE(op) \
	op(EDieState::Idle) \
	op(EDieState::Rolling) \
	op(EDieState::Stopped) \
	op(EDieState::Invalid) 

enum class EDieState : uint8;
template<> struct TIsUEnumClass<EDieState> { enum { Value = true }; };
template<> UEDICE_API UEnum* StaticEnum<EDieState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
