using UnrealBuildTool;
using System.Collections.Generic;

public class test_claude_01EditorTarget : TargetRules
{
	public test_claude_01EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		ExtraModuleNames.Add("test_claude_01");
	}
}
