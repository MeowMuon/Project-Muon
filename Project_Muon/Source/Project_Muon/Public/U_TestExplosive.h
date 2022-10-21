// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <PhysicsEngine/RadialForceComponent.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "U_TestExplosive.generated.h"

UCLASS()
class PROJECT_MUON_API AU_TestExplosive : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AU_TestExplosive();

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> m_ParticleEffect;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* m_StaticMeshComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		URadialForceComponent* m_RadialForceComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
