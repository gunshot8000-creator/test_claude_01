#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "PlayerCameraComponent.generated.h"

class ACharacter;
class UCharacterMovementComponent;

UCLASS(ClassGroup=(Camera), meta=(BlueprintSpawnableComponent))
class TEST_CLAUDE_01_API UPlayerCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:
	UPlayerCameraComponent();

	// Called by AMyCharacter on jump and land
	void OnOwnerJumped();
	void OnOwnerLanded(float LandingZVelocity);

	// FOV settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|FOV")
	float DefaultFOV = 90.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|FOV")
	float SprintFOV = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|FOV")
	float FOVInterpSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|FOV")
	float SpeedFOVThreshold = 400.0f;

	// Shake settings
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Shake")
	TSubclassOf<UCameraShakeBase> JumpShakeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Shake")
	TSubclassOf<UCameraShakeBase> LandShakeClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Shake")
	float LandShakeVelocityScale = 0.005f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera|Shake")
	float MaxLandShakeScale = 2.0f;

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void TriggerShake(TSubclassOf<UCameraShakeBase> ShakeClass, float Scale);

	UPROPERTY()
	ACharacter* OwnerCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwnerMovement;
};
