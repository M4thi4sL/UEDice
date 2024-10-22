// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PDA_Dice.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UEDICE_PDA_Dice_generated_h
#error "PDA_Dice.generated.h already included, missing '#pragma once' in PDA_Dice.h"
#endif
#define UEDICE_PDA_Dice_generated_h

#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPDA_Dice(); \
	friend struct Z_Construct_UClass_UPDA_Dice_Statics; \
public: \
	DECLARE_CLASS(UPDA_Dice, UPDA_Base, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UEDice"), NO_API) \
	DECLARE_SERIALIZER(UPDA_Dice)


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_29_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPDA_Dice(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UPDA_Dice(UPDA_Dice&&); \
	UPDA_Dice(const UPDA_Dice&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPDA_Dice); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPDA_Dice); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPDA_Dice) \
	NO_API virtual ~UPDA_Dice();


#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_26_PROLOG
#define FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_29_INCLASS_NO_PURE_DECLS \
	FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> UEDICE_API UClass* StaticClass<class UPDA_Dice>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h


#define FOREACH_ENUM_EDICETYPE(op) \
	op(EDiceType::D2) \
	op(EDiceType::D4) \
	op(EDiceType::D6) \
	op(EDiceType::D8) \
	op(EDiceType::D10) \
	op(EDiceType::D12) \
	op(EDiceType::D20) 

enum class EDiceType : uint8;
template<> struct TIsUEnumClass<EDiceType> { enum { Value = true }; };
template<> UEDICE_API UEnum* StaticEnum<EDiceType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
