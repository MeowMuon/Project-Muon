// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MU_FirstCharacter.generated.h"


UCLASS()
class PROJECT_MUON_API AMU_FirstCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMU_FirstCharacter();
	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> m_ProjectileClass;

protected:
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* m_CameraComp;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* m_SpringArmComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void move_forward(float value);
	void move_right(float value);

	void primary_attack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
