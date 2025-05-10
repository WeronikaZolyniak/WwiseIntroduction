// Copyright Audiokinetic 2024


#include "IntroCharacter.h"
#include "AkAudioEvent.h"
#include "AkComponent.h"
#include "AkSwitchValue.h"
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
	UE_LOG(LogTemp, Warning, TEXT("kick event"));
	
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

