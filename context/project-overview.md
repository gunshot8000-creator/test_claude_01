# Project Overview: test_claude_01

## Engine
- Unreal Engine 5.6
- Installed at: `C:\Program Files\Epic Games\UE_5.6`

## Project
- Name: `test_claude_01`
- Type: Code project (C++)
- uproject: `g:\Unreal Projects\test_claude_01\test_claude_01.uproject`

## Module
- Module name: `test_claude_01`
- Type: Runtime, Default loading phase
- Primary game module (`IMPLEMENT_PRIMARY_GAME_MODULE`)

## Plugins Enabled
- `ModelingToolsEditorMode` (Editor only)
- `GameplayStateTree`

## Source Files
```
Source/
  test_claude_01.Target.cs          # Game target rules
  test_claude_01Editor.Target.cs    # Editor target rules
  test_claude_01/
    test_claude_01.h                # Module header (CoreMinimal include)
    test_claude_01.cpp              # Module implementation
    test_claude_01.Build.cs         # Module build rules
    MyActorComponent.h              # Custom ActorComponent
    MyActorComponent.cpp
```

## MyActorComponent
- Extends `UActorComponent`
- `BlueprintSpawnableComponent`
- Exposed property: `MyFloat` (float, EditAnywhere/BlueprintReadWrite)
- Exposed function: `DoSomething()` (BlueprintCallable) — logs owner name
- Tick enabled by default
