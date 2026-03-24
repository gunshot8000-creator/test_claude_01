# UE5 C++ Quick Reference

## Naming Conventions
| Type | Prefix | Example |
|------|--------|---------|
| Class (UObject-derived) | `U` | `UMyActorComponent` |
| Actor | `A` | `AMyActor` |
| Struct | `F` | `FMyStruct` |
| Interface | `I` | `IMyInterface` |
| Enum | `E` | `EMyEnum` |
| Template | `T` | `TArray<>` |
| Non-UObject class | `F` or none | `FVector` |

## Common Macros
```cpp
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Name")
UFUNCTION(BlueprintCallable, Category = "Name")
GENERATED_BODY()
```

## UPROPERTY Specifiers
- `EditAnywhere` — editable in Details panel (instances + defaults)
- `EditDefaultsOnly` — editable only in Blueprint defaults
- `EditInstanceOnly` — editable only on placed instances
- `BlueprintReadWrite` — get/set in Blueprint
- `BlueprintReadOnly` — get only in Blueprint
- `VisibleAnywhere` — visible but not editable
- `Replicated` — networked replication

## UFUNCTION Specifiers
- `BlueprintCallable` — callable from Blueprint
- `BlueprintPure` — no execution pin (pure node)
- `BlueprintImplementableEvent` — implement in Blueprint, call from C++
- `BlueprintNativeEvent` — implement in C++ with Blueprint override

## Logging
```cpp
UE_LOG(LogTemp, Log,     TEXT("Message: %s"), *SomeString);
UE_LOG(LogTemp, Warning, TEXT("Warning"));
UE_LOG(LogTemp, Error,   TEXT("Error"));
```

## Common Includes
```cpp
#include "CoreMinimal.h"           // Always include first
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
```

## Getting Common Objects
```cpp
GetWorld()                    // UWorld*
GetOwner()                    // AActor* (from component)
GetGameInstance()             // UGameInstance*
GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("msg"));
```

## Module Build.cs — Common Dependencies
```csharp
PublicDependencyModuleNames.AddRange(new string[] {
    "Core", "CoreUObject", "Engine", "InputCore",
    "EnhancedInput",    // Enhanced Input
    "UMG",              // UI / Widgets
    "NavigationSystem", // NavMesh / AI
    "AIModule",         // AI controllers
    "GameplayTasks",    // Gameplay ability tasks
});
```
