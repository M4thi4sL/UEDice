// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEDice/Public/PDA_Base.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePDA_Base() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UPrimaryDataAsset();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Base();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Base_NoRegister();
UPackage* Z_Construct_UPackage__Script_UEDice();
// End Cross Module References

// Begin Class UPDA_Base
void UPDA_Base::StaticRegisterNativesUPDA_Base()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPDA_Base);
UClass* Z_Construct_UClass_UPDA_Base_NoRegister()
{
	return UPDA_Base::StaticClass();
}
struct Z_Construct_UClass_UPDA_Base_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "PDA_Base.h" },
		{ "ModuleRelativePath", "Public/PDA_Base.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Icon_MetaData[] = {
		{ "AssetBundles", "UI" },
		{ "Category", "Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Thumbnail for the item\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Thumbnail for the item" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "AssetBundles", "UI" },
		{ "Category", "Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Name for the name.\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Name for the name." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "AssetBundles", "UI" },
		{ "Category", "Setup" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The description for this item.\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Base.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The description for this item." },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_Icon;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPDA_Base>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UPDA_Base_Statics::NewProp_Icon = { "Icon", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Base, Icon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Icon_MetaData), NewProp_Icon_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UPDA_Base_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Base, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UPDA_Base_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Base, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPDA_Base_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Base_Statics::NewProp_Icon,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Base_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Base_Statics::NewProp_Description,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Base_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPDA_Base_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPrimaryDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_UEDice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Base_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPDA_Base_Statics::ClassParams = {
	&UPDA_Base::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPDA_Base_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Base_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Base_Statics::Class_MetaDataParams), Z_Construct_UClass_UPDA_Base_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPDA_Base()
{
	if (!Z_Registration_Info_UClass_UPDA_Base.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPDA_Base.OuterSingleton, Z_Construct_UClass_UPDA_Base_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPDA_Base.OuterSingleton;
}
template<> UEDICE_API UClass* StaticClass<UPDA_Base>()
{
	return UPDA_Base::StaticClass();
}
UPDA_Base::UPDA_Base(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPDA_Base);
UPDA_Base::~UPDA_Base() {}
// End Class UPDA_Base

// Begin Registration
struct Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPDA_Base, UPDA_Base::StaticClass, TEXT("UPDA_Base"), &Z_Registration_Info_UClass_UPDA_Base, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPDA_Base), 3524434384U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_2252799210(TEXT("/Script/UEDice"),
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Base_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
