// Fill out your copyright notice in the Description page of Project Settings.


#include "CompatComponent.h"
#include "MaxArena/Weapon/Weapon.h"
#include "MaxArena/Character/Hero.h"
#include "Engine/SkeletalMeshSocket.h"

// Sets default values for this component's properties
UCompatComponent::UCompatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCompatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCompatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCompatComponent::EquipWeapon(class AWeapon* WeaponToEquip)
{
	if(WeaponToEquip == nullptr || OwningCharacter == nullptr) return;
	EquippedWeapon = WeaponToEquip;
	const USkeletalMeshSocket* WeaponSocket = OwningCharacter->GetMesh()->GetSocketByName(FName("WeaponSocket"));
	if(WeaponSocket)
	{
		WeaponSocket->AttachActor(EquippedWeapon, OwningCharacter->GetMesh());
	}
	EquippedWeapon->SetOwner(OwningCharacter);
}





