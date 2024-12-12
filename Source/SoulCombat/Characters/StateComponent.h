// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateComponent.generated.h"

#include "GameplayTagContainer.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SOULCOMBAT_API UStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateComponent();

	UPROPERTY(EditAnywhere)
	bool bCanMove{ true };

	UPROPERTY(EditAnywhere)
	FGameplayTag CurrentState;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetState(FGameplayTag NewState);

	UFUNCTION(BlueprintCallable)
	bool IsCurrentStateEqualToAny(FGameplayTagContainer StatesToCheck);
};
