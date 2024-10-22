// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEDice/Public/DiceThrower.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDiceThrower() {}

// Begin Cross Module References
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UArrowComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_ADiceActor_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_ADiceThrower();
UEDICE_API UClass* Z_Construct_UClass_ADiceThrower_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Dice_NoRegister();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature();
UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_UEDice();
// End Cross Module References

// Begin Delegate FOnDieThrown
struct Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics
{
	struct DiceThrower_eventOnDieThrown_Parms
	{
		ADiceActor* ThrownDie;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Declare various dynamic multicast delegates for broadcasting events\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Declare various dynamic multicast delegates for broadcasting events" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ThrownDie;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::NewProp_ThrownDie = { "ThrownDie", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventOnDieThrown_Parms, ThrownDie), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::NewProp_ThrownDie,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "OnDieThrown__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::DiceThrower_eventOnDieThrown_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::DiceThrower_eventOnDieThrown_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceThrower::FOnDieThrown_DelegateWrapper(const FMulticastScriptDelegate& OnDieThrown, ADiceActor* ThrownDie)
{
	struct DiceThrower_eventOnDieThrown_Parms
	{
		ADiceActor* ThrownDie;
	};
	DiceThrower_eventOnDieThrown_Parms Parms;
	Parms.ThrownDie=ThrownDie;
	OnDieThrown.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieThrown

// Begin Delegate FOnDieSpawned
struct Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics
{
	struct DiceThrower_eventOnDieSpawned_Parms
	{
		ADiceActor* SpawnedDie;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnedDie;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::NewProp_SpawnedDie = { "SpawnedDie", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventOnDieSpawned_Parms, SpawnedDie), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::NewProp_SpawnedDie,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "OnDieSpawned__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::DiceThrower_eventOnDieSpawned_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::DiceThrower_eventOnDieSpawned_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceThrower::FOnDieSpawned_DelegateWrapper(const FMulticastScriptDelegate& OnDieSpawned, ADiceActor* SpawnedDie)
{
	struct DiceThrower_eventOnDieSpawned_Parms
	{
		ADiceActor* SpawnedDie;
	};
	DiceThrower_eventOnDieSpawned_Parms Parms;
	Parms.SpawnedDie=SpawnedDie;
	OnDieSpawned.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnDieSpawned

// Begin Delegate FOnDiceCleared
struct Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "OnDiceCleared__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceThrower::FOnDiceCleared_DelegateWrapper(const FMulticastScriptDelegate& OnDiceCleared)
{
	OnDiceCleared.ProcessMulticastDelegate<UObject>(NULL);
}
// End Delegate FOnDiceCleared

// Begin Delegate FOnTotalChanged
struct Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics
{
	struct DiceThrower_eventOnTotalChanged_Parms
	{
		FText NewResult;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_NewResult;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::NewProp_NewResult = { "NewResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventOnTotalChanged_Parms, NewResult), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::NewProp_NewResult,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "OnTotalChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::DiceThrower_eventOnTotalChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::DiceThrower_eventOnTotalChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void ADiceThrower::FOnTotalChanged_DelegateWrapper(const FMulticastScriptDelegate& OnTotalChanged, const FText& NewResult)
{
	struct DiceThrower_eventOnTotalChanged_Parms
	{
		FText NewResult;
	};
	DiceThrower_eventOnTotalChanged_Parms Parms;
	Parms.NewResult=NewResult;
	OnTotalChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
// End Delegate FOnTotalChanged

// Begin Class ADiceThrower Function AddDice
struct Z_Construct_UFunction_ADiceThrower_AddDice_Statics
{
	struct DiceThrower_eventAddDice_Parms
	{
		UPDA_Dice* Dice;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Dice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceThrower_AddDice_Statics::NewProp_Dice = { "Dice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventAddDice_Parms, Dice), Z_Construct_UClass_UPDA_Dice_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceThrower_AddDice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_AddDice_Statics::NewProp_Dice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_AddDice_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_AddDice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "AddDice", nullptr, nullptr, Z_Construct_UFunction_ADiceThrower_AddDice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_AddDice_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceThrower_AddDice_Statics::DiceThrower_eventAddDice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_AddDice_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_AddDice_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceThrower_AddDice_Statics::DiceThrower_eventAddDice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceThrower_AddDice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_AddDice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execAddDice)
{
	P_GET_OBJECT(UPDA_Dice,Z_Param_Dice);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddDice(Z_Param_Dice);
	P_NATIVE_END;
}
// End Class ADiceThrower Function AddDice

// Begin Class ADiceThrower Function ClearDice
struct Z_Construct_UFunction_ADiceThrower_ClearDice_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to reset and delete all spawned dice\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to reset and delete all spawned dice" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_ClearDice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "ClearDice", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_ClearDice_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_ClearDice_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ADiceThrower_ClearDice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_ClearDice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execClearDice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearDice();
	P_NATIVE_END;
}
// End Class ADiceThrower Function ClearDice

// Begin Class ADiceThrower Function LaunchDie
struct Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics
{
	struct DiceThrower_eventLaunchDie_Parms
	{
		ADiceActor* Die;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to launch a single die\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to launch a single die" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventLaunchDie_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::NewProp_Die,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "LaunchDie", nullptr, nullptr, Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::DiceThrower_eventLaunchDie_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::DiceThrower_eventLaunchDie_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceThrower_LaunchDie()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_LaunchDie_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execLaunchDie)
{
	P_GET_OBJECT(ADiceActor,Z_Param_Die);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->LaunchDie(Z_Param_Die);
	P_NATIVE_END;
}
// End Class ADiceThrower Function LaunchDie

// Begin Class ADiceThrower Function OnDiceResult
struct Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics
{
	struct DiceThrower_eventOnDiceResult_Parms
	{
		ADiceActor* Die;
		FText Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called when a dice broadcasts its result\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called when a dice broadcasts its result" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventOnDiceResult_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventOnDiceResult_Parms, Result), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::NewProp_Die,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "OnDiceResult", nullptr, nullptr, Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::DiceThrower_eventOnDiceResult_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::DiceThrower_eventOnDiceResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceThrower_OnDiceResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_OnDiceResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execOnDiceResult)
{
	P_GET_OBJECT(ADiceActor,Z_Param_Die);
	P_GET_PROPERTY(FTextProperty,Z_Param_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDiceResult(Z_Param_Die,Z_Param_Result);
	P_NATIVE_END;
}
// End Class ADiceThrower Function OnDiceResult

// Begin Class ADiceThrower Function OnDieClicked
struct Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics
{
	struct DiceThrower_eventOnDieClicked_Parms
	{
		ADiceActor* Die;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventOnDieClicked_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::NewProp_Die,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "OnDieClicked", nullptr, nullptr, Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::DiceThrower_eventOnDieClicked_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::DiceThrower_eventOnDieClicked_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceThrower_OnDieClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_OnDieClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execOnDieClicked)
{
	P_GET_OBJECT(ADiceActor,Z_Param_Die);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnDieClicked(Z_Param_Die);
	P_NATIVE_END;
}
// End Class ADiceThrower Function OnDieClicked

// Begin Class ADiceThrower Function RemoveDice
struct Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics
{
	struct DiceThrower_eventRemoveDice_Parms
	{
		UPDA_Dice* Dice;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Dice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::NewProp_Dice = { "Dice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventRemoveDice_Parms, Dice), Z_Construct_UClass_UPDA_Dice_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::NewProp_Dice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "RemoveDice", nullptr, nullptr, Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::DiceThrower_eventRemoveDice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::DiceThrower_eventRemoveDice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceThrower_RemoveDice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_RemoveDice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execRemoveDice)
{
	P_GET_OBJECT(UPDA_Dice,Z_Param_Dice);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveDice(Z_Param_Dice);
	P_NATIVE_END;
}
// End Class ADiceThrower Function RemoveDice

// Begin Class ADiceThrower Function RerollAll
struct Z_Construct_UFunction_ADiceThrower_RerollAll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reroll the existing spawned dice.\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reroll the existing spawned dice." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_RerollAll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "RerollAll", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RerollAll_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_RerollAll_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ADiceThrower_RerollAll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_RerollAll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execRerollAll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RerollAll();
	P_NATIVE_END;
}
// End Class ADiceThrower Function RerollAll

// Begin Class ADiceThrower Function RerollDice
struct Z_Construct_UFunction_ADiceThrower_RerollDice_Statics
{
	struct DiceThrower_eventRerollDice_Parms
	{
		ADiceActor* Die;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Reroll the existing spawned dice.\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Reroll the existing spawned dice." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Die;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::NewProp_Die = { "Die", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DiceThrower_eventRerollDice_Parms, Die), Z_Construct_UClass_ADiceActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::NewProp_Die,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "RerollDice", nullptr, nullptr, Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::PropPointers), sizeof(Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::DiceThrower_eventRerollDice_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::DiceThrower_eventRerollDice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ADiceThrower_RerollDice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_RerollDice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execRerollDice)
{
	P_GET_OBJECT(ADiceActor,Z_Param_Die);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RerollDice(Z_Param_Die);
	P_NATIVE_END;
}
// End Class ADiceThrower Function RerollDice

// Begin Class ADiceThrower Function SpawnDice
struct Z_Construct_UFunction_ADiceThrower_SpawnDice_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Function to spawn dice\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Function to spawn dice" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ADiceThrower_SpawnDice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ADiceThrower, nullptr, "SpawnDice", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ADiceThrower_SpawnDice_Statics::Function_MetaDataParams), Z_Construct_UFunction_ADiceThrower_SpawnDice_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_ADiceThrower_SpawnDice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ADiceThrower_SpawnDice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(ADiceThrower::execSpawnDice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SpawnDice();
	P_NATIVE_END;
}
// End Class ADiceThrower Function SpawnDice

// Begin Class ADiceThrower
void ADiceThrower::StaticRegisterNativesADiceThrower()
{
	UClass* Class = ADiceThrower::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "AddDice", &ADiceThrower::execAddDice },
		{ "ClearDice", &ADiceThrower::execClearDice },
		{ "LaunchDie", &ADiceThrower::execLaunchDie },
		{ "OnDiceResult", &ADiceThrower::execOnDiceResult },
		{ "OnDieClicked", &ADiceThrower::execOnDieClicked },
		{ "RemoveDice", &ADiceThrower::execRemoveDice },
		{ "RerollAll", &ADiceThrower::execRerollAll },
		{ "RerollDice", &ADiceThrower::execRerollDice },
		{ "SpawnDice", &ADiceThrower::execSpawnDice },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADiceThrower);
UClass* Z_Construct_UClass_ADiceThrower_NoRegister()
{
	return ADiceThrower::StaticClass();
}
struct Z_Construct_UClass_ADiceThrower_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DiceThrower.h" },
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieThrown_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event that will broadcast when a die is thrown\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event that will broadcast when a die is thrown" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDiceCleared_MetaData[] = {
		{ "Category", "Dice" },
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnResultChanged_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event dispatcher for broadcasting a new total result of the dice\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event dispatcher for broadcasting a new total result of the dice" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnDieSpawned_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Event that will broadcast when a die is spawned\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Event that will broadcast when a die is spawned" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugArrow_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The arrow component for visualizing the throw direction\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The arrow component for visualizing the throw direction" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnBox_MetaData[] = {
		{ "Category", "Debug" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Box component for visualizing the spawn area\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Box component for visualizing the spawn area" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceArray_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Array of dice data assets\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Array of dice data assets" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LaunchForce_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Force applied to launch the dice\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Force applied to launch the dice" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SpawnBoxExtent_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Box extent for spawning dice\n" },
#endif
		{ "ModuleRelativePath", "Public/DiceThrower.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Box extent for spawning dice" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieThrown;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDiceCleared;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnResultChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDieSpawned;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DebugArrow;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SpawnBox;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DiceArray_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DiceArray;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LaunchForce;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SpawnBoxExtent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ADiceThrower_AddDice, "AddDice" }, // 1643112777
		{ &Z_Construct_UFunction_ADiceThrower_ClearDice, "ClearDice" }, // 4018169271
		{ &Z_Construct_UFunction_ADiceThrower_LaunchDie, "LaunchDie" }, // 1723471300
		{ &Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature, "OnDiceCleared__DelegateSignature" }, // 2831216281
		{ &Z_Construct_UFunction_ADiceThrower_OnDiceResult, "OnDiceResult" }, // 360679931
		{ &Z_Construct_UFunction_ADiceThrower_OnDieClicked, "OnDieClicked" }, // 2975282972
		{ &Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature, "OnDieSpawned__DelegateSignature" }, // 2920593424
		{ &Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature, "OnDieThrown__DelegateSignature" }, // 2915035110
		{ &Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature, "OnTotalChanged__DelegateSignature" }, // 1617849201
		{ &Z_Construct_UFunction_ADiceThrower_RemoveDice, "RemoveDice" }, // 2172114937
		{ &Z_Construct_UFunction_ADiceThrower_RerollAll, "RerollAll" }, // 3158266888
		{ &Z_Construct_UFunction_ADiceThrower_RerollDice, "RerollDice" }, // 890125637
		{ &Z_Construct_UFunction_ADiceThrower_SpawnDice, "SpawnDice" }, // 3935179133
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADiceThrower>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnDieThrown = { "OnDieThrown", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, OnDieThrown), Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieThrown_MetaData), NewProp_OnDieThrown_MetaData) }; // 2915035110
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnDiceCleared = { "OnDiceCleared", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, OnDiceCleared), Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDiceCleared_MetaData), NewProp_OnDiceCleared_MetaData) }; // 2831216281
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnResultChanged = { "OnResultChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, OnResultChanged), Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnResultChanged_MetaData), NewProp_OnResultChanged_MetaData) }; // 1617849201
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnDieSpawned = { "OnDieSpawned", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, OnDieSpawned), Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnDieSpawned_MetaData), NewProp_OnDieSpawned_MetaData) }; // 2920593424
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_DebugArrow = { "DebugArrow", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, DebugArrow), Z_Construct_UClass_UArrowComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugArrow_MetaData), NewProp_DebugArrow_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_SpawnBox = { "SpawnBox", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, SpawnBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnBox_MetaData), NewProp_SpawnBox_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_DiceArray_Inner = { "DiceArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UPDA_Dice_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_DiceArray = { "DiceArray", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, DiceArray), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceArray_MetaData), NewProp_DiceArray_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_LaunchForce = { "LaunchForce", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, LaunchForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LaunchForce_MetaData), NewProp_LaunchForce_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ADiceThrower_Statics::NewProp_SpawnBoxExtent = { "SpawnBoxExtent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceThrower, SpawnBoxExtent), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SpawnBoxExtent_MetaData), NewProp_SpawnBoxExtent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADiceThrower_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnDieThrown,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnDiceCleared,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnResultChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_OnDieSpawned,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_DebugArrow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_SpawnBox,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_DiceArray_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_DiceArray,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_LaunchForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceThrower_Statics::NewProp_SpawnBoxExtent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceThrower_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADiceThrower_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UEDice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceThrower_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADiceThrower_Statics::ClassParams = {
	&ADiceThrower::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_ADiceThrower_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_ADiceThrower_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceThrower_Statics::Class_MetaDataParams), Z_Construct_UClass_ADiceThrower_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADiceThrower()
{
	if (!Z_Registration_Info_UClass_ADiceThrower.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADiceThrower.OuterSingleton, Z_Construct_UClass_ADiceThrower_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADiceThrower.OuterSingleton;
}
template<> UEDICE_API UClass* StaticClass<ADiceThrower>()
{
	return ADiceThrower::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADiceThrower);
ADiceThrower::~ADiceThrower() {}
// End Class ADiceThrower

// Begin Registration
struct Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADiceThrower, ADiceThrower::StaticClass, TEXT("ADiceThrower"), &Z_Registration_Info_UClass_ADiceThrower, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADiceThrower), 565491554U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_2549910031(TEXT("/Script/UEDice"),
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceThrower_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
