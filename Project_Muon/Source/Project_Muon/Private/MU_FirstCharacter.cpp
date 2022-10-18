// Fill out your copyright notice in the Description page of Project Settings.


#include "MU_FirstCharacter.h"

// Sets default values
AMU_FirstCharacter::AMU_FirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	m_SpringArmComp->SetupAttachment(RootComponent);

	m_CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	m_CameraComp->SetupAttachment(m_SpringArmComp);
}

// Called when the game starts or when spawned
void AMU_FirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMU_FirstCharacter::move_forward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AMU_FirstCharacter::move_right(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

// Called every frame
void AMU_FirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMU_FirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMU_FirstCharacter::move_forward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMU_FirstCharacter::move_right);
	PlayerInputComponent->BindAxis("TurnRight", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnUp", this, &APawn::AddControllerPitchInput);
}

