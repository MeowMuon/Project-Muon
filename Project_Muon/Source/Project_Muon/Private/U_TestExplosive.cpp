// Fill out your copyright notice in the Description page of Project Settings.


#include "U_TestExplosive.h"

// Sets default values
AU_TestExplosive::AU_TestExplosive()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	m_RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("Radial Force");

	RootComponent = m_StaticMeshComp;
	m_RadialForceComp->SetupAttachment(m_StaticMeshComp);

	m_RadialForceComp->Radius = 1000.f;
}

// Called when the game starts or when spawned
void AU_TestExplosive::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AU_TestExplosive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

