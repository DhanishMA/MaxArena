// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MaxArena/MaxArenaGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMaxArenaGameModeBase() {}
// Cross Module References
	MAXARENA_API UClass* Z_Construct_UClass_AMaxArenaGameModeBase_NoRegister();
	MAXARENA_API UClass* Z_Construct_UClass_AMaxArenaGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MaxArena();
// End Cross Module References
	void AMaxArenaGameModeBase::StaticRegisterNativesAMaxArenaGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AMaxArenaGameModeBase_NoRegister()
	{
		return AMaxArenaGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMaxArenaGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMaxArenaGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MaxArena,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMaxArenaGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MaxArenaGameModeBase.h" },
		{ "ModuleRelativePath", "MaxArenaGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMaxArenaGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMaxArenaGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMaxArenaGameModeBase_Statics::ClassParams = {
		&AMaxArenaGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMaxArenaGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMaxArenaGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMaxArenaGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMaxArenaGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMaxArenaGameModeBase, 4038299699);
	template<> MAXARENA_API UClass* StaticClass<AMaxArenaGameModeBase>()
	{
		return AMaxArenaGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMaxArenaGameModeBase(Z_Construct_UClass_AMaxArenaGameModeBase, &AMaxArenaGameModeBase::StaticClass, TEXT("/Script/MaxArena"), TEXT("AMaxArenaGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMaxArenaGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
