// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Interview2 : ModuleRules
{
	public Interview2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "UMG", "MediaAssets" });
	}
}
