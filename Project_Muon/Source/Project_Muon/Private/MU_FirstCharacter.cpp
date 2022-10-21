// Fill out your copyright notice in the Description page of Project Settings.


#include "MU_FirstCharacter.h"

// Sets default values
AMU_FirstCharacter::AMU_FirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	m_CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	m_SpringArmComp->SetupAttachment(RootComponent);
	m_CameraComp->SetupAttachment(m_SpringArmComp);

	m_SpringArmComp->bUsePawnControlRotation = true;
	m_SpringArmComp->TargetArmLength = 300.f;
	m_SpringArmComp->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;

	m_AttackDelay = 0.5f;

	m_InteractComp = CreateDefaultSubobject<UMU_InteractComponent>("Interact Component");
}

// Called when the game starts or when spawned
void AMU_FirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMU_FirstCharacter::move_forward(float value)
{
	AddMovementInput(FRotator(0, GetControlRotation().Yaw, 0).Vector(), value);
}

void AMU_FirstCharacter::move_right(float value)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::Y), value);
}

void AMU_FirstCharacter::primary_attack()
{
	PlayAnimMontage(m_AttackAnim);

	GetWorldTimerManager().SetTimer(m_TimerHandel_PrimaryAttack, this, &AMU_FirstCharacter::primary_attack_elapsed, m_AttackDelay);
}

void AMU_FirstCharacter::primary_attack_elapsed()
{
	FTransform SpawnTransform = FTransform(GetControlRotation(), GetActorLocation());
	FActorSpawnParameters SpawnParameter;
	SpawnParameter.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AActor>(m_ProjectileClass, SpawnTransform, SpawnParameter);
}

void AMU_FirstCharacter::primary_interact()
{
	if (m_InteractComp)
	{
		m_InteractComp->PrimaryInteract();
	}
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

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &AMU_FirstCharacter::primary_attack);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &AMU_FirstCharacter::primary_interact);
}

