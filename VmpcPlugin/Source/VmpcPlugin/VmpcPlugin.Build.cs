using UnrealBuildTool;
using System.IO;

public class VmpcPlugin : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

    private string ThirdPartyPath
    {
        get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
    }

    public VmpcPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // Not sure if needed
        Definitions.Add("_CRT_SECURE_NO_WARNINGS=1");
        Definitions.Add("BOOST_DISABLE_ABI_HEADERS=1");

        // Needed configurations in order to run Boost
        bUseRTTI = true;
        bEnableExceptions = true;

        PublicIncludePaths.AddRange(new string[] { "VmpcPlugin/Public" });

        PrivateIncludePaths.AddRange(new string[] { "VmpcPlugin/Private", });

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AudioMixer", "SoundUtilities", "Synthesis", "VmpcThirdParty", "RHI", "RenderCore" });


        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        DynamicallyLoadedModuleNames.AddRange(new string[] { "VmpcPlugin" });
    }
}
