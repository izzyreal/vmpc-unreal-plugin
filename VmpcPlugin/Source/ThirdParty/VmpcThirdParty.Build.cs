// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using System.IO;
using System;

namespace UnrealBuildTool.Rules
{
    public class VmpcThirdParty : ModuleRules
    {
        private string ModulePath
        {
            get { return ModuleDirectory; }
        }

        private string BinariesPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../Binaries/")); }
        }

        public VmpcThirdParty(ReadOnlyTargetRules Target) : base(Target)
        {
            // Tell Unreal that this Module only imports Third-Party-Assets
            Type = ModuleType.External;

            LoadVmpcThirdParty(Target);
        }

        public bool LoadVmpcThirdParty(ReadOnlyTargetRules Target)
        {
            bool isLibrarySupported = false;
            bool bDebug = (Target.Configuration == UnrealTargetConfiguration.Debug && BuildConfiguration.bDebugBuildsActuallyUseDebugCRT);

            if (Target.Platform == UnrealTargetPlatform.Win64)
            {
                isLibrarySupported = true;

                // Explicitly name the used libraries
                //PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "Boost/lib/libboost_chrono-vc141-mt-1_64.lib"));
 
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "lib/moduru.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "lib/mpc.lib"));
                PublicAdditionalLibraries.Add(Path.Combine(ModulePath, "lib/ctoot.lib"));
            }

            if (isLibrarySupported)
            {
                PublicIncludePaths.Add(Path.Combine(ModulePath, "Boost/include/boost-1_64"));
                PublicIncludePaths.Add(Path.Combine(ModulePath, "include/moduru"));
                PublicIncludePaths.Add(Path.Combine(ModulePath, "include/mpc"));
                PublicIncludePaths.Add(Path.Combine(ModulePath, "include/ctoot"));
                PublicIncludePaths.Add(Path.Combine(ModulePath, "include/rapidjson/include"));

                // Not sure if needed
                Definitions.Add("_CRT_SECURE_NO_WARNINGS=1");
                Definitions.Add("BOOST_DISABLE_ABI_HEADERS=1");

                // Needed configurations in order to run Boost
                bUseRTTI = true;
                bEnableExceptions = true;
                //bEnableUndefinedIdentifierWarnings = false;
            }

            Definitions.Add(string.Format("WITH_VMPCTHIRDPARTY_BINDING={0}", isLibrarySupported ? 1 : 0));
            Definitions.Add(string.Format("WITH_BOOST_BINDING={0}", isLibrarySupported ? 1 : 0));

            return isLibrarySupported;
        }
    }
}
