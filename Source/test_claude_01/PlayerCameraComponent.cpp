#include "PlayerCameraComponent.h"
#include "JumpCameraShake.h"
#include "LandCameraShake.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraShakeBase.h"
#include "Camera/PlayerCameraManager.h"
#include "GameFramework/PlayerController.h"

UPlayerCameraComponent::UPlayerCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	OwnerCharacter = nullptr;
	OwnerMovement  = nullptr;
}

void UPlayerCameraComponent::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	if (OwnerCharacter)
	{
		OwnerMovement = OwnerCharacter->GetCharacterMovement();
	}

	SetFieldOfView(DefaultFOV);
}

void UPlayerCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!OwnerMovement)
		return;

	const float Speed       = OwnerMovement->Velocity.Size();
	const float TargetFOV   = (Speed > SpeedFOVThreshold) ? SprintFOV : DefaultFOV;
	const float NewFOV      = FMath::FInterpTo(FieldOfView, TargetFOV, DeltaTime, FOVInterpSpeed);

	SetFieldOfView(NewFOV);
}

void UPlayerCameraComponent::OnOwnerJumped()
{
	TriggerShake(JumpShakeClass, 1.0f);
}

void UPlayerCameraComponent::OnOwnerLanded(float LandingZVelocity)
{
	const float Speed = FMath::Abs(LandingZVelocity);
	const float Scale = FMath::Clamp(Speed * LandShakeVelocityScale, 0.1f, MaxLandShakeScale);
	TriggerShake(LandShakeClass, Scale);
}

void UPlayerCameraComponent::TriggerShake(TSubclassOf<UCameraShakeBase> ShakeClass, float Scale)
{
	if (!ShakeClass || !OwnerCharacter)
		return;

	APlayerController* PC = Cast<APlayerController>(OwnerCharacter->GetController());
	if (!PC || !PC->PlayerCameraManager)
		return;

	PC->PlayerCameraManager->StartCameraShake(ShakeClass, Scale);
}
