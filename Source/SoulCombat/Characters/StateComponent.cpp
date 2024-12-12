// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/StateComponent.h"
#include "StateComponent.h"

// Sets default values for this component's properties
UStateComponent::UStateComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStateComponent::SetState(FGameplayTag NewState)
{
	CurrentState = NewState;
}

bool UStateComponent::IsCurrentStateEqualToAny(FGameplayTagContainer StatesToCheck)
{
	return StatesToCheck.HasTag(CurrentState);
}
