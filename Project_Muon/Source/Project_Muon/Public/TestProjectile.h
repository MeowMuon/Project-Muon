// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Particles/ParticleSystemComponent.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestProjectile.generated.h"

UCLASS()
class PROJECT_MUON_API ATestProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		USphereComponent* m_SphereComp;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* m_ParticleComp;
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* m_MovementComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
