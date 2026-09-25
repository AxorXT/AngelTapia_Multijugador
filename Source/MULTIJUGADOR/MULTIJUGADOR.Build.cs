// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MULTIJUGADOR : ModuleRules
{
	public MULTIJUGADOR(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"OnlineSubsystem",
			"OnlineSubsystemUtils"
		});

		DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"MULTIJUGADOR",
			"MULTIJUGADOR/Variant_Platforming",
			"MULTIJUGADOR/Variant_Platforming/Animation",
			"MULTIJUGADOR/Variant_Combat",
			"MULTIJUGADOR/Variant_Combat/AI",
			"MULTIJUGADOR/Variant_Combat/Animation",
			"MULTIJUGADOR/Variant_Combat/Gameplay",
			"MULTIJUGADOR/Variant_Combat/Interfaces",
			"MULTIJUGADOR/Variant_Combat/UI",
			"MULTIJUGADOR/Variant_SideScrolling",
			"MULTIJUGADOR/Variant_SideScrolling/AI",
			"MULTIJUGADOR/Variant_SideScrolling/Gameplay",
			"MULTIJUGADOR/Variant_SideScrolling/Interfaces",
			"MULTIJUGADOR/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
