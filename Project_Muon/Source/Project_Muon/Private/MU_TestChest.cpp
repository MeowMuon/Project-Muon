// Fill out your copyright notice in the Description page of Project Settings.


#include "MU_TestChest.h"

void AMU_TestChest::Interact_Implementation(APawn* InstigatorPawn)
{
	if (bIsOpen)
	{
		m_Lid->SetRelativeRotation(FRotator(0, 0, 0));
		bIsOpen = false;
	}
	else
	{
		m_Lid->SetRelativeRotation(FRotator(90, 0, 0));
		bIsOpen = true;
	}
}

// Sets default values
AMU_TestChest::AMU_TestChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Chest = CreateDefaultSubobject<UStaticMeshComponent>("Chest");
	m_Lid = CreateDefaultSubobject<UStaticMeshComponent>("Lid");

	RootComponent = m_Chest;
	m_Lid->SetupAttachment(m_Chest);

	bIsOpen = false;
}

// Called when the game starts or when spawned
void AMU_TestChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMU_TestChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

