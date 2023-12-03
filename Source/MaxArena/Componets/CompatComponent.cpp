// Fill out your copyright notice in the Description page of Project Settings.


#include "CompatComponent.h"
#include "MaxArena/Weapon/Weapon.h"
#include "MaxArena/Character/Hero.h"
#include "Engine/SkeletalMeshSocket.h"

UCompatComponent::UCompatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UCompatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCompatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCompatComponent::EquipWeapon(class AWeapon* WeaponToEquip)
{
	if(WeaponToEquip == nullptr || OwningCharacter == nullptr) return;
	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped);
	const USkeletalMeshSocket* WeaponSocket = OwningCharacter->GetMesh()->GetSocketByName(FName("WeaponSocket"));
	if(WeaponSocket)
	{
		WeaponSocket->AttachActor(EquippedWeapon, OwningCharacter->GetMesh());
	}
	EquippedWeapon->SetOwner(OwningCharacter);
}

void UCompatComponent::SetShouldFire(bool bShouldFire)
{
	if(bShouldFire)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fired"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Fire Halted"));
	}
}







