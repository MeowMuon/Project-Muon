// Fill out your copyright notice in the Description page of Project Settings.


#include "MU_TestProjectile.h"

// Sets default values
AMU_TestProjectile::AMU_TestProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_SphereComp = CreateDefaultSubobject<USphereComponent>("Sphere");
	m_ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>("Particle");
	m_MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("Movement Component");

	RootComponent = m_SphereComp;
	m_ParticleComp->SetupAttachment(RootComponent);

	m_SphereComp->SetCollisionObjectType(ECC_WorldDynamic);
	m_SphereComp->SetCollisionProfileName("MU_Projectile");

	m_MovementComp->InitialSpeed = 1000.f;
	m_MovementComp->ProjectileGravityScale = 0.f;
	m_MovementComp->bRotationFollowsVelocity = true;
	m_MovementComp->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void AMU_TestProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMU_TestProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

