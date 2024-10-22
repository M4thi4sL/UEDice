// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEDice/Public/StringUtils.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeStringUtils() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UEDICE_API UClass* Z_Construct_UClass_UStringUtils();
UEDICE_API UClass* Z_Construct_UClass_UStringUtils_NoRegister();
UPackage* Z_Construct_UPackage__Script_UEDice();
// End Cross Module References

// Begin Class UStringUtils Function PadInteger
struct Z_Construct_UFunction_UStringUtils_PadInteger_Statics
{
	struct StringUtils_eventPadInteger_Parms
	{
		int32 Number;
		int32 MinWidth;
		FString PaddingChar;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "StringUtilities" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Convert a given integer to String and pad it with the given character if necessary.\n" },
#endif
		{ "ModuleRelativePath", "Public/StringUtils.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Convert a given integer to String and pad it with the given character if necessary." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PaddingChar_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_Number;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinWidth;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PaddingChar;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_Number = { "Number", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StringUtils_eventPadInteger_Parms, Number), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_MinWidth = { "MinWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StringUtils_eventPadInteger_Parms, MinWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_PaddingChar = { "PaddingChar", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StringUtils_eventPadInteger_Parms, PaddingChar), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PaddingChar_MetaData), NewProp_PaddingChar_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(StringUtils_eventPadInteger_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UStringUtils_PadInteger_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_Number,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_MinWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_PaddingChar,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UStringUtils_PadInteger_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UStringUtils_PadInteger_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStringUtils_PadInteger_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UStringUtils, nullptr, "PadInteger", nullptr, nullptr, Z_Construct_UFunction_UStringUtils_PadInteger_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UStringUtils_PadInteger_Statics::PropPointers), sizeof(Z_Construct_UFunction_UStringUtils_PadInteger_Statics::StringUtils_eventPadInteger_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStringUtils_PadInteger_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStringUtils_PadInteger_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_UStringUtils_PadInteger_Statics::StringUtils_eventPadInteger_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UStringUtils_PadInteger()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStringUtils_PadInteger_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStringUtils::execPadInteger)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Number);
	P_GET_PROPERTY(FIntProperty,Z_Param_MinWidth);
	P_GET_PROPERTY(FStrProperty,Z_Param_PaddingChar);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UStringUtils::PadInteger(Z_Param_Number,Z_Param_MinWidth,Z_Param_PaddingChar);
	P_NATIVE_END;
}
// End Class UStringUtils Function PadInteger

// Begin Class UStringUtils
void UStringUtils::StaticRegisterNativesUStringUtils()
{
	UClass* Class = UStringUtils::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "PadInteger", &UStringUtils::execPadInteger },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UStringUtils);
UClass* Z_Construct_UClass_UStringUtils_NoRegister()
{
	return UStringUtils::StaticClass();
}
struct Z_Construct_UClass_UStringUtils_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "StringUtils.h" },
		{ "ModuleRelativePath", "Public/StringUtils.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UStringUtils_PadInteger, "PadInteger" }, // 3531804631
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStringUtils>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UStringUtils_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UEDice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStringUtils_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStringUtils_Statics::ClassParams = {
	&UStringUtils::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStringUtils_Statics::Class_MetaDataParams), Z_Construct_UClass_UStringUtils_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UStringUtils()
{
	if (!Z_Registration_Info_UClass_UStringUtils.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStringUtils.OuterSingleton, Z_Construct_UClass_UStringUtils_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStringUtils.OuterSingleton;
}
template<> UEDICE_API UClass* StaticClass<UStringUtils>()
{
	return UStringUtils::StaticClass();
}
UStringUtils::UStringUtils(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UStringUtils);
UStringUtils::~UStringUtils() {}
// End Class UStringUtils

// Begin Registration
struct Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UStringUtils, UStringUtils::StaticClass, TEXT("UStringUtils"), &Z_Registration_Info_UClass_UStringUtils, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStringUtils), 3480982669U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_1035942746(TEXT("/Script/UEDice"),
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_StringUtils_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
