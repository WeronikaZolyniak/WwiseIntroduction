// Copyright Audiokinetic 2024


#include "IntroCharacter.h"
#include "AkAudioEvent.h"
#include "AkComponent.h"
#include "AkSwitchValue.h"
#include "AkGameplayStatics.h"
#include "Wwise/API/WwiseSoundEngineAPI.h"

// Sets default values
AIntroCharacter::AIntroCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AIntroCharacter::BeginPlay()
{
	Super::BeginPlay();
	UAkGameplayStatics::SetSwitch(HighFrequencySwitchValue, this);
}

// Called every frame
void AIntroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AIntroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
}

void AIntroCharacter::PostKickEvent()
{
	
	if (auto* SoundEngine = IWwiseSoundEngineAPI::Get())
	{
		if (KickEvent)
		{
			if (!KickEvent->IsLoaded())
			{
				KickEvent->LoadData();
			}
			KickEvent->PostOnActor(this, {}, 0, false);
		}
	}
}

void AIntroCharacter::PlayHighLowTone()
{
	if (auto* SoundEngine = IWwiseSoundEngineAPI::Get())
	{
		if (ToneEvent)
		{
			if (!ToneEvent->IsLoaded())
			{
				ToneEvent->LoadData();
			}
			ToneEvent->PostOnActor(this, {}, 0, false);
		}
	}
}

void AIntroCharacter::ChangeFrequency()
{
	if (HighFrequency && HighFrequencySwitchValue && LowFrequencySwitchValue)
	{
		HighFrequency = 0;
		UAkGameplayStatics::SetSwitch(LowFrequencySwitchValue, this);
	}
	else if (HighFrequencySwitchValue && LowFrequencySwitchValue)
	{
		HighFrequency = 1;
		UAkGameplayStatics::SetSwitch(HighFrequencySwitchValue, this);
	}
}

