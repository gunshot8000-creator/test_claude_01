# Build & Launch Guide

## Prerequisites

### Required (installed 2026-03-25)
- **.NET Framework 4.8 Developer Pack**
  - Needed by UBT for SwarmInterface module
  - Install via: `winget install Microsoft.DotNet.Framework.DeveloperPack_4 --version 4.8 --silent --accept-package-agreements --accept-source-agreements`

### Visual Studio
- Visual Studio 2022 Build Tools installed at:
  `C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools`
- MSVC toolchain: `14.44.35207`
- Note: UBT warns that `14.44` is not the preferred version (`14.38` is preferred), but builds succeed

## Build (Editor target)

```powershell
powershell.exe -Command "& 'C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat' test_claude_01Editor Win64 Development 'g:\Unreal Projects\test_claude_01\test_claude_01.uproject' -waitmutex"
```

Typical build time: ~2 min (first build), ~10–30s (incremental)

## Launch Editor

```powershell
powershell.exe -Command "Start-Process 'C:\Program Files\Epic Games\UE_5.6\Engine\Binaries\Win64\UnrealEditor.exe' -ArgumentList '\"g:\Unreal Projects\test_claude_01\test_claude_01.uproject\"'"
```

## Notes
- The project originally had no `Target.cs` files — these were added manually:
  - `Source/test_claude_01.Target.cs`
  - `Source/test_claude_01Editor.Target.cs`
- Use `BuildSettingsVersion.V5` and `IncludeOrderVersion.Latest` for UE 5.6
- Do NOT run Build.bat directly from bash with spaces in path — wrap in `powershell.exe -Command` or `cmd.exe /c`
