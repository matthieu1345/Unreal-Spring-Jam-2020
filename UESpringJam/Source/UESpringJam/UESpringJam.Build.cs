// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UESpringJam : ModuleRules
{
	public UESpringJam(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
