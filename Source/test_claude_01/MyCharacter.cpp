#include "MyCharacter.h"
#include "PlayerCameraComponent.h"
#include "JumpCameraShake.h"
#include "LandCameraShake.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "Animation/AnimInstance.h"
#include "Engine/SkeletalMesh.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// Spring arm
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 400.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	// Custom camera component
	CameraComp = CreateDefaultSubobject<UPlayerCameraComponent>(TEXT("PlayerCamera"));
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;
	CameraComp->JumpShakeClass = UJumpCameraShake::StaticClass();
	CameraComp->LandShakeClass = ULandCameraShake::StaticClass();

	// Movement
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	GetCharacterMovement()->JumpZVelocity = 700.0f;
	GetCharacterMovement()->AirControl = 0.35f;

	// Auto-load mannequin mesh
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(
		TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny_Simple"));
	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
		GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
		GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	}

	// Auto-load animation blueprint
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimClass(
		TEXT("/Game/Characters/Mannequins/Anims/Unarmed/ABP_Unarmed"));
	if (AnimClass.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimClass.Class);
	}

	// Auto-load input assets
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMC(
		TEXT("/Game/Input/IMC_Default"));
	if (IMC.Succeeded()) DefaultMappingContext = IMC.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> MoveIA(
		TEXT("/Game/Input/Actions/IA_Move"));
	if (MoveIA.Succeeded()) MoveAction = MoveIA.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> LookIA(
		TEXT("/Game/Input/Actions/IA_Look"));
	if (LookIA.Succeeded()) LookAction = LookIA.Object;

	static ConstructorHelpers::FObjectFinder<UInputAction> JumpIA(
		TEXT("/Game/Input/Actions/IA_Jump"));
	if (JumpIA.Succeeded()) JumpAction = JumpIA.Object;
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Sub =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Sub->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(JumpAction, ETriggerEvent::Started,   this, &ACharacter::Jump);
		EIC->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EIC->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);
		EIC->BindAction(LookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);
	}
}

void AMyCharacter::OnJumped_Implementation()
{
	Super::OnJumped_Implementation();
	if (CameraComp)
	{
		CameraComp->OnOwnerJumped();
	}
}

void AMyCharacter::Landed(const FHitResult& Hit)
{
	const float ImpactZ = GetVelocity().Z;
	Super::Landed(Hit);
	if (CameraComp)
	{
		CameraComp->OnOwnerLanded(ImpactZ);
	}
}

void AMyCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	if (!Controller)
		return;

	const FRotator Rotation  = Controller->GetControlRotation();
	const FRotator YawOnly   = FRotator(0.f, Rotation.Yaw, 0.f);
	const FVector  Forward   = FRotationMatrix(YawOnly).GetUnitAxis(EAxis::X);
	const FVector  Right     = FRotationMatrix(YawOnly).GetUnitAxis(EAxis::Y);

	AddMovementInput(Forward, Axis.Y);
	AddMovementInput(Right,   Axis.X);
}

void AMyCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D Axis = Value.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(Axis.Y);
}
