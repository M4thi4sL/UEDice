// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UEDice/Public/PDA_Dice.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePDA_Dice() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Base();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Dice();
UEDICE_API UClass* Z_Construct_UClass_UPDA_Dice_NoRegister();
UEDICE_API UEnum* Z_Construct_UEnum_UEDice_EDiceType();
UPackage* Z_Construct_UPackage__Script_UEDice();
// End Cross Module References

// Begin Enum EDiceType
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDiceType;
static UEnum* EDiceType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDiceType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDiceType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UEDice_EDiceType, (UObject*)Z_Construct_UPackage__Script_UEDice(), TEXT("EDiceType"));
	}
	return Z_Registration_Info_UEnum_EDiceType.OuterSingleton;
}
template<> UEDICE_API UEnum* StaticEnum<EDiceType>()
{
	return EDiceType_StaticEnum();
}
struct Z_Construct_UEnum_UEDice_EDiceType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Enum for defining dice types */" },
#endif
		{ "D10.DisplayName", "D10" },
		{ "D10.Name", "EDiceType::D10" },
		{ "D12.DisplayName", "D12" },
		{ "D12.Name", "EDiceType::D12" },
		{ "D2.DisplayName", "D2" },
		{ "D2.Name", "EDiceType::D2" },
		{ "D20.DisplayName", "D20" },
		{ "D20.Name", "EDiceType::D20" },
		{ "D4.DisplayName", "D4" },
		{ "D4.Name", "EDiceType::D4" },
		{ "D6.DisplayName", "D6" },
		{ "D6.Name", "EDiceType::D6" },
		{ "D8.DisplayName", "D8" },
		{ "D8.Name", "EDiceType::D8" },
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enum for defining dice types" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDiceType::D2", (int64)EDiceType::D2 },
		{ "EDiceType::D4", (int64)EDiceType::D4 },
		{ "EDiceType::D6", (int64)EDiceType::D6 },
		{ "EDiceType::D8", (int64)EDiceType::D8 },
		{ "EDiceType::D10", (int64)EDiceType::D10 },
		{ "EDiceType::D12", (int64)EDiceType::D12 },
		{ "EDiceType::D20", (int64)EDiceType::D20 },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UEDice_EDiceType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_UEDice,
	nullptr,
	"EDiceType",
	"EDiceType",
	Z_Construct_UEnum_UEDice_EDiceType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_UEDice_EDiceType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UEDice_EDiceType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UEDice_EDiceType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_UEDice_EDiceType()
{
	if (!Z_Registration_Info_UEnum_EDiceType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDiceType.InnerSingleton, Z_Construct_UEnum_UEDice_EDiceType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDiceType.InnerSingleton;
}
// End Enum EDiceType

// Begin Class UPDA_Dice
void UPDA_Dice::StaticRegisterNativesUPDA_Dice()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPDA_Dice);
UClass* Z_Construct_UClass_UPDA_Dice_NoRegister()
{
	return UPDA_Dice::StaticClass();
}
struct Z_Construct_UClass_UPDA_Dice_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A data asset to hold information about the dice's faces, visual representation, and metadata.\n */" },
#endif
		{ "IncludePath", "PDA_Dice.h" },
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A data asset to hold information about the dice's faces, visual representation, and metadata." },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FaceLabels_MetaData[] = {
		{ "Category", "DiceData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** A map associating face index with its label (e.g., 1, 2, 3, etc. or any custom string)\n     INT32 matches the socket name of the static mesh */" },
#endif
		{ "EditCondition", "bHasValidMesh" },
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A map associating face index with its label (e.g., 1, 2, 3, etc. or any custom string)\n    INT32 matches the socket name of the static mesh" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FaceNormals_MetaData[] = {
		{ "Category", "DiceData" },
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceMesh_MetaData[] = {
		{ "AssetBundles", "Game" },
		{ "Category", "DiceData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The mesh to use for rendering the dice (soft pointer)\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The mesh to use for rendering the dice (soft pointer)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceMaterial_MetaData[] = {
		{ "AssetBundles", "Game" },
		{ "Category", "DiceData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The material to apply to the dice mesh (soft pointer)\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The material to apply to the dice mesh (soft pointer)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceType_MetaData[] = {
		{ "Category", "DiceData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Enum representing the type of dice (D6, D20, etc.)\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Enum representing the type of dice (D6, D20, etc.)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiceClass_MetaData[] = {
		{ "AssetBundles", "Game" },
		{ "Category", "DiceData" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// The class to use for this dice type (e.g., a subclass of AActor or UIndividualDice) (soft pointer)\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "The class to use for this dice type (e.g., a subclass of AActor or UIndividualDice) (soft pointer)" },
#endif
	};
#if WITH_EDITORONLY_DATA
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasValidMesh_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Boolean property for EditCondition to check if a valid mesh is provided\n" },
#endif
		{ "ModuleRelativePath", "Public/PDA_Dice.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Boolean property for EditCondition to check if a valid mesh is provided" },
#endif
	};
#endif // WITH_EDITORONLY_DATA
#endif // WITH_METADATA
	static const UECodeGen_Private::FTextPropertyParams NewProp_FaceLabels_ValueProp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FaceLabels_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_FaceLabels;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FaceNormals_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FaceNormals;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DiceMesh;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_DiceMaterial;
	static const UECodeGen_Private::FBytePropertyParams NewProp_DiceType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_DiceType;
	static const UECodeGen_Private::FSoftClassPropertyParams NewProp_DiceClass;
#if WITH_EDITORONLY_DATA
	static void NewProp_bHasValidMesh_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasValidMesh;
#endif // WITH_EDITORONLY_DATA
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPDA_Dice>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceLabels_ValueProp = { "FaceLabels", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceLabels_Key_KeyProp = { "FaceLabels_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceLabels = { "FaceLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Dice, FaceLabels), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FaceLabels_MetaData), NewProp_FaceLabels_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceNormals_Inner = { "FaceNormals", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceNormals = { "FaceNormals", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Dice, FaceNormals), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FaceNormals_MetaData), NewProp_FaceNormals_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceMesh = { "DiceMesh", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Dice, DiceMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceMesh_MetaData), NewProp_DiceMesh_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceMaterial = { "DiceMaterial", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Dice, DiceMaterial), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceMaterial_MetaData), NewProp_DiceMaterial_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceType = { "DiceType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Dice, DiceType), Z_Construct_UEnum_UEDice_EDiceType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceType_MetaData), NewProp_DiceType_MetaData) }; // 15908508
const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceClass = { "DiceClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPDA_Dice, DiceClass), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiceClass_MetaData), NewProp_DiceClass_MetaData) };
#if WITH_EDITORONLY_DATA
void Z_Construct_UClass_UPDA_Dice_Statics::NewProp_bHasValidMesh_SetBit(void* Obj)
{
	((UPDA_Dice*)Obj)->bHasValidMesh = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UPDA_Dice_Statics::NewProp_bHasValidMesh = { "bHasValidMesh", nullptr, (EPropertyFlags)0x0040000800002000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UPDA_Dice), &Z_Construct_UClass_UPDA_Dice_Statics::NewProp_bHasValidMesh_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasValidMesh_MetaData), NewProp_bHasValidMesh_MetaData) };
#endif // WITH_EDITORONLY_DATA
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPDA_Dice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceLabels_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceLabels_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceNormals_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_FaceNormals,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceMesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceMaterial,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_DiceClass,
#if WITH_EDITORONLY_DATA
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPDA_Dice_Statics::NewProp_bHasValidMesh,
#endif // WITH_EDITORONLY_DATA
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Dice_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UPDA_Dice_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UPDA_Base,
	(UObject* (*)())Z_Construct_UPackage__Script_UEDice,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Dice_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UPDA_Dice_Statics::ClassParams = {
	&UPDA_Dice::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UPDA_Dice_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Dice_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPDA_Dice_Statics::Class_MetaDataParams), Z_Construct_UClass_UPDA_Dice_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UPDA_Dice()
{
	if (!Z_Registration_Info_UClass_UPDA_Dice.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPDA_Dice.OuterSingleton, Z_Construct_UClass_UPDA_Dice_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UPDA_Dice.OuterSingleton;
}
template<> UEDICE_API UClass* StaticClass<UPDA_Dice>()
{
	return UPDA_Dice::StaticClass();
}
UPDA_Dice::UPDA_Dice(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UPDA_Dice);
UPDA_Dice::~UPDA_Dice() {}
// End Class UPDA_Dice

// Begin Registration
struct Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDiceType_StaticEnum, TEXT("EDiceType"), &Z_Registration_Info_UEnum_EDiceType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 15908508U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UPDA_Dice, UPDA_Dice::StaticClass, TEXT("UPDA_Dice"), &Z_Registration_Info_UClass_UPDA_Dice, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPDA_Dice), 195730752U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_2953052465(TEXT("/Script/UEDice"),
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UEDice_Plugins_UEDice_UEDice_Source_UEDice_Public_PDA_Dice_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
