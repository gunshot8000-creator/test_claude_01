#include "LandCameraShake.h"

ULandCameraShake::ULandCameraShake(const FObjectInitializer& OI) : Super(OI)
{
	OscillationDuration     = 0.4f;
	OscillationBlendInTime  = 0.0f;
	OscillationBlendOutTime = 0.2f;

	RotOscillation.Pitch.Amplitude = 3.0f;
	RotOscillation.Pitch.Frequency = 8.0f;

	RotOscillation.Roll.Amplitude = 1.5f;
	RotOscillation.Roll.Frequency = 6.0f;

	LocOscillation.Z.Amplitude = 5.0f;
	LocOscillation.Z.Frequency = 10.0f;
}
