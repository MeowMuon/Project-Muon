// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "MU_InteractComponent.h"

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

protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<AActor> m_ProjectileClass;
	UPROPERTY(EditAnywhere, Category = "Attack")
		UAnimMontage* m_AttackAnim;
	UPROPERTY(EditAnywhere, Category = "Attack")
		float m_AttackDelay;

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* m_CameraComp;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* m_SpringArmComp;
	UPROPERTY(VisibleAnywhere)
		UMU_InteractComponent* m_InteractComp;

	FTimerHandle m_TimerHandel_PrimaryAttack;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void move_forward(float value);
	void move_right(float value);

	void primary_attack();
	void primary_attack_elapsed();
	void primary_interact();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
