// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEDice/Public/DiceActor.h"
#include "Runtime/Engine/Classes/Engine/HitResult.h"
#include "Runtime/InputCore/Classes/InputCoreTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDiceActor() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
INPUTCORE_API UScriptStruct* Z_Construct_UScriptStruct_FKey();
UEDICE_API UClass* Z_Construct_UClass_ADiceActor();
UEDICE_API UClass* Z_Construct_UClass_ADiceActor_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_ADiceDecal_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Dice_NoRegister();
UEDICE_API UEnum* Z_Construct_UEnum_UEDice_EDieState();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_UEDice();
// End Cross Module References

// Begin Enum EDieState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDieState;
static UEnum* EDieState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDieState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDieState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UEDice_EDieState, (UObject*)Z_Construct_UPackage__Script_UEDice(), TEXT("EDieState"));
	}
	return Z_Registration_Info_UEnum_EDieState.OuterSingleton;
}
template<> UEDICE_API UEnum* StaticEnum<EDieState>()
{
	return EDieState_StaticEnum();
}
struct Z_Construct_UEnum_UEDice_EDieState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A visual actor representation of a dice.\n */" },
#endif
		{ "Idle.DisplayName", "Idle" },
		{ "Idle.Name", "EDieState::Idle" },
		{ "Invalid.DisplayName", "Invalid" },
		{ "Invalid.Name", "EDieState::Invalid" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
		{ "Rolling.DisplayName", "Rolling" },
		{ "Rolling.Name", "EDieState::Rolling" },
		{ "Stopped.DisplayName", "Stopped" },
		{ "Stopped.Name", "EDieState::Stopped" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A visual actor representation of a dice." },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDieState::Idle", (int64)EDieState::Idle },
		{ "EDieState::Rolling", (int64)EDieState::Rolling },
		{ "EDieState::Stopped", (int64)EDieState::Stopped },
		{ "EDieState::Invalid", (int64)EDieState::Invalid },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UEDice_EDieState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_UEDice,
	nullptr,
	"EDieState",
	"EDieState",
	Z_Construct_UEnum_UEDice_EDieState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_UEDice_EDieState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UEDice_EDieState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UEDice_EDieState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_UEDice_EDieState()
{
	if (!Z_Registration_Info_UEnum_EDieState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDieState.InnerSingleton, Z_Construct_UEnum_UEDice_EDieState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDieState.InnerSingleton;
}
// End Enum EDieState

// Begin Delegate FOnDieResult
struct Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics
{
	struct DiceActor_eventOnDieResult_Parms
	{
		ADiceActor* Die;
		FText Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Delegate signature for broadcasting dice result\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Delegate signature for broadcasting dice result" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieResult_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieResult_Parms, Result), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::NewProp_Die,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "OnDieResult__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::DiceActor_eventOnDieResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::DiceActor_eventOnDieResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceActor::FOnDieResult_DelegateWrapper(const FMulticastScriptDelegate& OnDieResult, ADiceActor* Die, const FText& Result)
{
	struct DiceActor_eventOnDieResult_Parms
	{
		ADiceActor* Die;
		FText Result;
	};
	DiceActor_eventOnDieResult_Parms Parms;
	Parms.Die=Die;
	Parms.Result=Result;
	OnDieResult.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieResult

// Begin Delegate FOnDieStateChanged
struct Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics
{
	struct DiceActor_eventOnDieStateChanged_Parms
	{
		ADiceActor* Die;
		EDieState NewDieState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewDieState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewDieState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieStateChanged_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::NewProp_NewDieState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::NewProp_NewDieState = { "NewDieState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieStateChanged_Parms, NewDieState), Z_Construct_UEnum_UEDice_EDieState, METADATA_PARAMS(0, nullptr) }; // 3908884128
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::NewProp_Die,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::NewProp_NewDieState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::NewProp_NewDieState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "OnDieStateChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::DiceActor_eventOnDieStateChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::DiceActor_eventOnDieStateChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceActor::FOnDieStateChanged_DelegateWrapper(const FMulticastScriptDelegate& OnDieStateChanged, ADiceActor* Die, EDieState NewDieState)
{
	struct DiceActor_eventOnDieStateChanged_Parms
	{
		ADiceActor* Die;
		EDieState NewDieState;
	};
	DiceActor_eventOnDieStateChanged_Parms Parms;
	Parms.Die=Die;
	Parms.NewDieState=NewDieState;
	OnDieStateChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieStateChanged

// Begin Delegate FOnDieHover
struct Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics
{
	struct DiceActor_eventOnDieHover_Parms
	{
		ADiceActor* Die;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieHover_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::NewProp_Die,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "OnDieHover__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::DiceActor_eventOnDieHover_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::DiceActor_eventOnDieHover_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceActor::FOnDieHover_DelegateWrapper(const FMulticastScriptDelegate& OnDieHover, ADiceActor* Die)
{
	struct DiceActor_eventOnDieHover_Parms
	{
		ADiceActor* Die;
	};
	DiceActor_eventOnDieHover_Parms Parms;
	Parms.Die=Die;
	OnDieHover.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieHover

// Begin Delegate FOnDieHoverEnd
struct Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics
{
	struct DiceActor_eventOnDieHoverEnd_Parms
	{
		ADiceActor* Die;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieHoverEnd_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::NewProp_Die,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "OnDieHoverEnd__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::DiceActor_eventOnDieHoverEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::DiceActor_eventOnDieHoverEnd_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceActor::FOnDieHoverEnd_DelegateWrapper(const FMulticastScriptDelegate& OnDieHoverEnd, ADiceActor* Die)
{
	struct DiceActor_eventOnDieHoverEnd_Parms
	{
		ADiceActor* Die;
	};
	DiceActor_eventOnDieHoverEnd_Parms Parms;
	Parms.Die=Die;
	OnDieHoverEnd.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieHoverEnd

// Begin Delegate FOnDieClicked
struct Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics
{
	struct DiceActor_eventOnDieClicked_Parms
	{
		ADiceActor* Die;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventOnDieClicked_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::NewProp_Die,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "OnDieClicked__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::DiceActor_eventOnDieClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::DiceActor_eventOnDieClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceActor::FOnDieClicked_DelegateWrapper(const FMulticastScriptDelegate& OnDieClicked, ADiceActor* Die)
{
	struct DiceActor_eventOnDieClicked_Parms
	{
		ADiceActor* Die;
	};
	DiceActor_eventOnDieClicked_Parms Parms;
	Parms.Die=Die;
	OnDieClicked.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieClicked

// Begin Class ADiceActor Function GetDieState
struct Z_Construct_UFunction_ADiceActor_GetDieState_Statics
{
	struct DiceActor_eventGetDieState_Parms
	{
		EDieState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ADiceActor_GetDieState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ADiceActor_GetDieState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventGetDieState_Parms, ReturnValue), Z_Construct_UEnum_UEDice_EDieState, METADATA_PARAMS(0, nullptr) }; // 3908884128
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_GetDieState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_GetDieState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_GetDieState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_GetDieState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_GetDieState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "GetDieState", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_GetDieState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_GetDieState_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_GetDieState_Statics::DiceActor_eventGetDieState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_GetDieState_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_GetDieState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_GetDieState_Statics::DiceActor_eventGetDieState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_GetDieState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_GetDieState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execGetDieState)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDieState*)Z_Param__Result=P_THIS->GetDieState();
	P_NATIVE_END;
}
// End Class ADiceActor Function GetDieState

// Begin Class ADiceActor Function HandleBeginCursorOver
struct Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics
{
	struct DiceActor_eventHandleBeginCursorOver_Parms
	{
		UPrimitiveComponent* TouchedComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event handler for mouse hover start\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event handler for mouse hover start" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TouchedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TouchedComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::NewProp_TouchedComponent = { "TouchedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleBeginCursorOver_Parms, TouchedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TouchedComponent_MetaData), NewProp_TouchedComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::NewProp_TouchedComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "HandleBeginCursorOver", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::DiceActor_eventHandleBeginCursorOver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::DiceActor_eventHandleBeginCursorOver_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execHandleBeginCursorOver)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchedComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleBeginCursorOver(Z_Param_TouchedComponent);
	P_NATIVE_END;
}
// End Class ADiceActor Function HandleBeginCursorOver

// Begin Class ADiceActor Function HandleEndCursorOver
struct Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics
{
	struct DiceActor_eventHandleEndCursorOver_Parms
	{
		UPrimitiveComponent* TouchedComponent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event handler for mouse hover end\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event handler for mouse hover end" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TouchedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TouchedComponent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::NewProp_TouchedComponent = { "TouchedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleEndCursorOver_Parms, TouchedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TouchedComponent_MetaData), NewProp_TouchedComponent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::NewProp_TouchedComponent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "HandleEndCursorOver", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::DiceActor_eventHandleEndCursorOver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::DiceActor_eventHandleEndCursorOver_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_HandleEndCursorOver()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_HandleEndCursorOver_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execHandleEndCursorOver)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchedComponent);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleEndCursorOver(Z_Param_TouchedComponent);
	P_NATIVE_END;
}
// End Class ADiceActor Function HandleEndCursorOver

// Begin Class ADiceActor Function HandleOnClicked
struct Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics
{
	struct DiceActor_eventHandleOnClicked_Parms
	{
		UPrimitiveComponent* TouchedComponent;
		FKey ButtonPressed;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event handler for mouse hover end\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event handler for mouse hover end" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TouchedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TouchedComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ButtonPressed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::NewProp_TouchedComponent = { "TouchedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnClicked_Parms, TouchedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TouchedComponent_MetaData), NewProp_TouchedComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::NewProp_ButtonPressed = { "ButtonPressed", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnClicked_Parms, ButtonPressed), Z_Construct_UScriptStruct_FKey, METADATA_PARAMS(0, nullptr) }; // 658672854
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::NewProp_TouchedComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::NewProp_ButtonPressed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "HandleOnClicked", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::DiceActor_eventHandleOnClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::DiceActor_eventHandleOnClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_HandleOnClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_HandleOnClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execHandleOnClicked)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchedComponent);
	P_GET_STRUCT(FKey,Z_Param_ButtonPressed);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnClicked(Z_Param_TouchedComponent,Z_Param_ButtonPressed);
	P_NATIVE_END;
}
// End Class ADiceActor Function HandleOnClicked

// Begin Class ADiceActor Function HandleOnHit
struct Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics
{
	struct DiceActor_eventHandleOnHit_Parms
	{
		UPrimitiveComponent* HitComponent;
		AActor* OtherActor;
		UPrimitiveComponent* OtherComponent;
		FVector NormalImpulse;
		FHitResult Hit;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OtherComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hit;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_HitComponent = { "HitComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnHit_Parms, HitComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitComponent_MetaData), NewProp_HitComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_OtherComponent = { "OtherComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnHit_Parms, OtherComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OtherComponent_MetaData), NewProp_OtherComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandleOnHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hit_MetaData), NewProp_Hit_MetaData) }; // 4100991306
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_HitComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_OtherActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_OtherComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_NormalImpulse,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::NewProp_Hit,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "HandleOnHit", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::DiceActor_eventHandleOnHit_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::DiceActor_eventHandleOnHit_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_HandleOnHit()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_HandleOnHit_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execHandleOnHit)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComponent);
	P_GET_OBJECT(AActor,Z_Param_OtherActor);
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent);
	P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnHit(Z_Param_HitComponent,Z_Param_OtherActor,Z_Param_OtherComponent,Z_Param_NormalImpulse,Z_Param_Out_Hit);
	P_NATIVE_END;
}
// End Class ADiceActor Function HandleOnHit

// Begin Class ADiceActor Function HandlePhysicsSleep
struct Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics
{
	struct DiceActor_eventHandlePhysicsSleep_Parms
	{
		UPrimitiveComponent* SleepingComponent;
		FName BoneName;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Handler for when the physics simulation goes to sleep\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Handler for when the physics simulation goes to sleep" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SleepingComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SleepingComponent;
	static const UECodeGen_Private::FNamePropertyParams NewProp_BoneName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::NewProp_SleepingComponent = { "SleepingComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandlePhysicsSleep_Parms, SleepingComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SleepingComponent_MetaData), NewProp_SleepingComponent_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::NewProp_BoneName = { "BoneName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventHandlePhysicsSleep_Parms, BoneName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::NewProp_SleepingComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::NewProp_BoneName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "HandlePhysicsSleep", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::DiceActor_eventHandlePhysicsSleep_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::DiceActor_eventHandlePhysicsSleep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execHandlePhysicsSleep)
{
	P_GET_OBJECT(UPrimitiveComponent,Z_Param_SleepingComponent);
	P_GET_PROPERTY(FNameProperty,Z_Param_BoneName);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandlePhysicsSleep(Z_Param_SleepingComponent,Z_Param_BoneName);
	P_NATIVE_END;
}
// End Class ADiceActor Function HandlePhysicsSleep

// Begin Class ADiceActor Function InitializeDice
struct Z_Construct_UFunction_ADiceActor_InitializeDice_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Initialize the dice actor based on the data asset\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Initialize the dice actor based on the data asset" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_InitializeDice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "InitializeDice", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_InitializeDice_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_InitializeDice_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ADiceActor_InitializeDice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_InitializeDice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execInitializeDice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InitializeDice();
	P_NATIVE_END;
}
// End Class ADiceActor Function InitializeDice

// Begin Class ADiceActor Function SetDieState
struct Z_Construct_UFunction_ADiceActor_SetDieState_Statics
{
	struct DiceActor_eventSetDieState_Parms
	{
		EDieState NewDieState;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NewDieState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_NewDieState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NewDieState;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_ADiceActor_SetDieState_Statics::NewProp_NewDieState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_ADiceActor_SetDieState_Statics::NewProp_NewDieState = { "NewDieState", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceActor_eventSetDieState_Parms, NewDieState), Z_Construct_UEnum_UEDice_EDieState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NewDieState_MetaData), NewProp_NewDieState_MetaData) }; // 3908884128
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceActor_SetDieState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_SetDieState_Statics::NewProp_NewDieState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceActor_SetDieState_Statics::NewProp_NewDieState,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_SetDieState_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceActor_SetDieState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceActor, nullptr, "SetDieState", nullptr, nullptr, Z_Construct_UFunction_ADiceActor_SetDieState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_SetDieState_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceActor_SetDieState_Statics::DiceActor_eventSetDieState_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceActor_SetDieState_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceActor_SetDieState_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceActor_SetDieState_Statics::DiceActor_eventSetDieState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceActor_SetDieState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceActor_SetDieState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceActor::execSetDieState)
{
	P_GET_ENUM(EDieState,Z_Param_NewDieState);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDieState(EDieState(Z_Param_NewDieState));
	P_NATIVE_END;
}
// End Class ADiceActor Function SetDieState

// Begin Class ADiceActor
void ADiceActor::StaticRegisterNativesADiceActor()
{
	UClass* Class = ADiceActor::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "GetDieState", &ADiceActor::execGetDieState },
		{ "HandleBeginCursorOver", &ADiceActor::execHandleBeginCursorOver },
		{ "HandleEndCursorOver", &ADiceActor::execHandleEndCursorOver },
		{ "HandleOnClicked", &ADiceActor::execHandleOnClicked },
		{ "HandleOnHit", &ADiceActor::execHandleOnHit },
		{ "HandlePhysicsSleep", &ADiceActor::execHandlePhysicsSleep },
		{ "InitializeDice", &ADiceActor::execInitializeDice },
		{ "SetDieState", &ADiceActor::execSetDieState },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADiceActor);
UClass* Z_Construct_UClass_ADiceActor_NoRegister()
{
	return ADiceActor::StaticClass();
}
struct Z_Construct_UClass_ADiceActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "DiceActor.h" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceMeshComponent_MetaData[] = {
		{ "Category", "Visual" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Static mesh component for visualizing the dice\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Static mesh component for visualizing the dice" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceData_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The data asset for this dice\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The data asset for this dice" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceDecal_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Dice Decal\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Dice Decal" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceHitSound_MetaData[] = {
		{ "Category", "Audio" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieResult_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event dispatcher for broadcasting the dice result\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event dispatcher for broadcasting the dice result" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieStateChanged_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event dispatcher for broadcasting when the result has changed.\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceActor.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event dispatcher for broadcasting when the result has changed." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieHover_MetaData[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieHoverEnd_MetaData[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieClicked_MetaData[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DiceMeshComponent;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DiceData;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DiceDecal;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DiceHitSound;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieResult;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieStateChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieHover;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieHoverEnd;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieClicked;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADiceActor_GetDieState, "GetDieState" }, // 3237975262
		{ &Z_Construct_UFunction_ADiceActor_HandleBeginCursorOver, "HandleBeginCursorOver" }, // 2243990385
		{ &Z_Construct_UFunction_ADiceActor_HandleEndCursorOver, "HandleEndCursorOver" }, // 2668448946
		{ &Z_Construct_UFunction_ADiceActor_HandleOnClicked, "HandleOnClicked" }, // 1625418682
		{ &Z_Construct_UFunction_ADiceActor_HandleOnHit, "HandleOnHit" }, // 3469234700
		{ &Z_Construct_UFunction_ADiceActor_HandlePhysicsSleep, "HandlePhysicsSleep" }, // 2784619673
		{ &Z_Construct_UFunction_ADiceActor_InitializeDice, "InitializeDice" }, // 180747631
		{ &Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature, "OnDieClicked__DelegateSignature" }, // 562535415
		{ &Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature, "OnDieHover__DelegateSignature" }, // 3816384691
		{ &Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature, "OnDieHoverEnd__DelegateSignature" }, // 3497172875
		{ &Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature, "OnDieResult__DelegateSignature" }, // 51301219
		{ &Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature, "OnDieStateChanged__DelegateSignature" }, // 2296021870
		{ &Z_Construct_UFunction_ADiceActor_SetDieState, "SetDieState" }, // 2554497623
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADiceActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceMeshComponent = { "DiceMeshComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, DiceMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceMeshComponent_MetaData), NewProp_DiceMeshComponent_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceData = { "DiceData", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, DiceData), Z_Construct_UClass_UPDA_Dice_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceData_MetaData), NewProp_DiceData_MetaData) };
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceDecal = { "DiceDecal", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, DiceDecal), Z_Construct_UClass_ADiceDecal_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceDecal_MetaData), NewProp_DiceDecal_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceHitSound = { "DiceHitSound", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, DiceHitSound), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceHitSound_MetaData), NewProp_DiceHitSound_MetaData) };
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieResult = { "OnDieResult", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, OnDieResult), Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieResult_MetaData), NewProp_OnDieResult_MetaData) }; // 51301219
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieStateChanged = { "OnDieStateChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, OnDieStateChanged), Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieStateChanged_MetaData), NewProp_OnDieStateChanged_MetaData) }; // 2296021870
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieHover = { "OnDieHover", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, OnDieHover), Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieHover_MetaData), NewProp_OnDieHover_MetaData) }; // 3816384691
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieHoverEnd = { "OnDieHoverEnd", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, OnDieHoverEnd), Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieHoverEnd_MetaData), NewProp_OnDieHoverEnd_MetaData) }; // 3497172875
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieClicked = { "OnDieClicked", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceActor, OnDieClicked), Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieClicked_MetaData), NewProp_OnDieClicked_MetaData) }; // 562535415
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADiceActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceMeshComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceDecal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_DiceHitSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieStateChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieHover,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieHoverEnd,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceActor_Statics::NewProp_OnDieClicked,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADiceActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UEDice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADiceActor_Statics::ClassParams = {
	&ADiceActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ADiceActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceActor_Statics::Class_MetaDataParams), Z_Construct_UClass_ADiceActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADiceActor()
{
	if (!Z_Registration_Info_UClass_ADiceActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADiceActor.OuterSingleton, Z_Construct_UClass_ADiceActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADiceActor.OuterSingleton;
}
template<> UEDICE_API UClass* StaticClass<ADiceActor>()
{
	return ADiceActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADiceActor);
ADiceActor::~ADiceActor() {}
// End Class ADiceActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDieState_StaticEnum, TEXT("EDieState"), &Z_Registration_Info_UEnum_EDieState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3908884128U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADiceActor, ADiceActor::StaticClass, TEXT("ADiceActor"), &Z_Registration_Info_UClass_ADiceActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADiceActor), 965743958U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_1301276396(TEXT("/Script/UEDice"),
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceActor_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
