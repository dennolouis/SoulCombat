// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEquipment.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ABaseEquipment::ABaseEquipment()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create and attach the StaticMesh component
    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(RootComponent); // Attach to RootComponent
}

void ABaseEquipment::EquipItem()
{
    UE_LOG(LogTemp, Log, TEXT("EquipItem called on %s"), *GetName());
}

// Called when the game starts or when spawned
void ABaseEquipment::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEquipment::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseEquipment::AttachToPlayer(FName SocketName)
{
    // Get the owner of this actor
    AActor* ActorOwner = GetOwner();
    if (!ActorOwner)
    {
        UE_LOG(LogTemp, Warning, TEXT("Owner not found!"));
        return;
    }

    // Cast the owner to ACharacter
    ACharacter* CharacterOwner = Cast<ACharacter>(ActorOwner);
    if (!CharacterOwner)
    {
        UE_LOG(LogTemp, Warning, TEXT("Owner is not a character!"));
        return;
    }

    // Get the character's skeletal mesh component
    USkeletalMeshComponent* MeshComponent = CharacterOwner->GetMesh();
    if (!MeshComponent)
    {
        UE_LOG(LogTemp, Warning, TEXT("Character mesh component not found!"));
        return;
    }

    // Attach this actor to the mesh component at the specified socket
    AttachToComponent(MeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, SocketName);

    UE_LOG(LogTemp, Log, TEXT("Actor attached to socket: %s"), *SocketName.ToString());

}

