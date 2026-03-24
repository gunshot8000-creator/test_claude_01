#include "JumpCameraShake.h"

UJumpCameraShake::UJumpCameraShake(const FObjectInitializer& OI) : Super(OI)
{
	OscillationDuration     = 0.25f;
	OscillationBlendInTime  = 0.05f;
	OscillationBlendOutTime = 0.1f;

	RotOscillation.Pitch.Amplitude = 1.5f;
	RotOscillation.Pitch.Frequency = 10.0f;

	RotOscillation.Roll.Amplitude = 0.5f;
	RotOscillation.Roll.Frequency = 8.0f;

	LocOscillation.Z.Amplitude = 2.0f;
	LocOscillation.Z.Frequency = 12.0f;
}
