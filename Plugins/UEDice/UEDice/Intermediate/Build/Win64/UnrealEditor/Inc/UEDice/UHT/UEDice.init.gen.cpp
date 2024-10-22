// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUEDice_init() {}
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature();
	UEDICE_API UFunction* Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_UEDice;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_UEDice()
	{
		if (!Z_Registration_Info_UPackage__Script_UEDice.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceActor_OnDieClicked__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceActor_OnDieHover__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceActor_OnDieHoverEnd__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceActor_OnDieResult__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceActor_OnDieStateChanged__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceThrower_OnDiceCleared__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceThrower_OnDieSpawned__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceThrower_OnDieThrown__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_ADiceThrower_OnTotalChanged__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/UEDice",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xC387B9C5,
				0x46B71C13,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_UEDice.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_UEDice.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_UEDice(Z_Construct_UPackage__Script_UEDice, TEXT("/Script/UEDice"), Z_Registration_Info_UPackage__Script_UEDice, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xC387B9C5, 0x46B71C13));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
