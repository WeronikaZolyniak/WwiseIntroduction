// Copyright Audiokinetic 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IntroCharacter.generated.h"

UCLASS()
class WWISEDEMOGAME_API AIntroCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AIntroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void PostKickEvent();

	UPROPERTY(EditAnywhere)
	class UAkAudioEvent* KickEvent;

	UPROPERTY(EditAnywhere)
	class UAkAudioEvent* ToneEvent;

	UPROPERTY(EditAnywhere)
	class UAkSwitchValue* HighFrequencySwitchValue;

	UPROPERTY(EditAnywhere)
	class UAkSwitchValue* LowFrequencySwitchValue;

	UFUNCTION(BlueprintCallable)
	void PlayHighLowTone();

	UFUNCTION(BlueprintCallable)
	void ChangeFrequency();

	bool HighFrequency = 1;

};
