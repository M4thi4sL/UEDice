// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEDice/Public/DiceDecal.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDiceDecal() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UDecalComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_ADiceDecal();
UEDICE_API UClass* Z_Construct_UClass_ADiceDecal_NoRegister();
UPackage* Z_Construct_UPackage__Script_UEDice();
// End Cross Module References

// Begin Class ADiceDecal
void ADiceDecal::StaticRegisterNativesADiceDecal()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADiceDecal);
UClass* Z_Construct_UClass_ADiceDecal_NoRegister()
{
	return ADiceDecal::StaticClass();
}
struct Z_Construct_UClass_ADiceDecal_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "DiceDecal.h" },
		{ "ModuleRelativePath", "Public/DiceDecal.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SceneRoot_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Root component for organizing the hierarchy\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceDecal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Root component for organizing the hierarchy" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Decal_MetaData[] = {
		{ "Category", "Dice" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Decal visualisation\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/DiceDecal.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Decal visualisation" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneRoot;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Decal;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADiceDecal>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceDecal_Statics::NewProp_SceneRoot = { "SceneRoot", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceDecal, SceneRoot), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SceneRoot_MetaData), NewProp_SceneRoot_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADiceDecal_Statics::NewProp_Decal = { "Decal", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADiceDecal, Decal), Z_Construct_UClass_UDecalComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Decal_MetaData), NewProp_Decal_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADiceDecal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceDecal_Statics::NewProp_SceneRoot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADiceDecal_Statics::NewProp_Decal,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceDecal_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_ADiceDecal_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_UEDice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceDecal_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ADiceDecal_Statics::ClassParams = {
	&ADiceDecal::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_ADiceDecal_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_ADiceDecal_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADiceDecal_Statics::Class_MetaDataParams), Z_Construct_UClass_ADiceDecal_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ADiceDecal()
{
	if (!Z_Registration_Info_UClass_ADiceDecal.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADiceDecal.OuterSingleton, Z_Construct_UClass_ADiceDecal_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ADiceDecal.OuterSingleton;
}
template<> UEDICE_API UClass* StaticClass<ADiceDecal>()
{
	return ADiceDecal::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ADiceDecal);
ADiceDecal::~ADiceDecal() {}
// End Class ADiceDecal

// Begin Registration
struct Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceDecal_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ADiceDecal, ADiceDecal::StaticClass, TEXT("ADiceDecal"), &Z_Registration_Info_UClass_ADiceDecal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADiceDecal), 72474922U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceDecal_h_1890286236(TEXT("/Script/UEDice"),
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceDecal_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_DiceDecal_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
