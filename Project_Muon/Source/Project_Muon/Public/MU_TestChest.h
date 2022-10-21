// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MU_Interact_Interface.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MU_TestChest.generated.h"

UCLASS()
class PROJECT_MUON_API AMU_TestChest : public AActor, public IMU_Interact_Interface
{
	GENERATED_BODY()

		void Interact_Implementation(APawn* InstigatorPawn);
	
public:	
	// Sets default values for this actor's properties
	AMU_TestChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* m_Chest;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* m_Lid;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool bIsOpen;

};
