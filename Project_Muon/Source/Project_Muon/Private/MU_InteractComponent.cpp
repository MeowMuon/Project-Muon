// Fill out your copyright notice in the Description page of Project Settings.


#include "MU_InteractComponent.h"

#include "DrawDebugHelpers.h"
// Sets default values for this component's properties
UMU_InteractComponent::UMU_InteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UMU_InteractComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryPram;
	ObjectQueryPram.AddObjectTypesToQuery(ECC_WorldDynamic);


	FVector Start;
	FRotator R;
	Start = GetOwner()->GetActorLocation();
	R = Cast<APawn>(GetOwner())->GetControlRotation();
	//GetActorEyesViewPoint(Start,R);
	FVector End;
	End = Start + (R.Vector() * 1000.f);

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(Hit,Start,End,ObjectQueryPram);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Emerald, false, 0.5f, 0, 10);

	AActor* HitActor = Hit.GetActor();
	if (HitActor)
	{
		if (HitActor->Implements<UMU_Interact_Interface>())
		{
			IMU_Interact_Interface::Execute_Interact(HitActor, Cast<APawn>(GetOwner()));
		}
	}
}


// Called when the game starts
void UMU_InteractComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMU_InteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

