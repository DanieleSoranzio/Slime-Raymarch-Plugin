// Copyright Epic Games, Inc. All Rights Reserved.

#include "SlimeCharacterPackage.h"

#define LOCTEXT_NAMESPACE "FSlimeCharacterPackageModule"

void FSlimeCharacterPackageModule::StartupModule()
{
	FString ShaderDirectory = FPaths::Combine(FPaths::ProjectDir(), TEXT("Plugins/SlimeCharacterPackage/Shaders"));
	AddShaderSourceDirectoryMapping("/Shaders", ShaderDirectory);
}

void FSlimeCharacterPackageModule::ShutdownModule()
{
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSlimeCharacterPackageModule, SlimeCharacterPackage)