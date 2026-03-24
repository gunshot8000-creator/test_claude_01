#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyActorComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TEST_CLAUDE_01_API UMyActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UMyActorComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Component")
	float MyFloat = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "My Component")
	void DoSomething();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
