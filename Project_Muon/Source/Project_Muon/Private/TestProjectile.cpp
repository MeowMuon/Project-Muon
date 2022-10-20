// Fill out your copyright notice in the Description page of Project Settings.


#include "TestProjectile.h"

// Sets default values
ATestProjectile::ATestProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereComp = CreateDefaultSubobject<USphereComponent>("Sphere");
	m_ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>("Particle");
	m_MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("Movement Component");

	RootComponent = m_SphereComp;
	m_ParticleComp->SetupAttachment(RootComponent);

	m_MovementComp->InitialSpeed = 1000.f;
	m_MovementComp->bRotationFollowsVelocity = true;
	m_MovementComp->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ATestProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

