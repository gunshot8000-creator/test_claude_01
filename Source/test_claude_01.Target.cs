using UnrealBuildTool;
using System.Collections.Generic;

public class test_claude_01Target : TargetRules
{
	public test_claude_01Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("test_claude_01");
	}
}
