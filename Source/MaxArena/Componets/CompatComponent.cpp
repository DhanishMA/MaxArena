// Fill out your copyright notice in the Description page of Project Settings.


#include "CompatComponent.h"
#include "MaxArena/Weapon/Weapon.h"
#include "MaxArena/Character/Hero.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"

UCompatComponent::UCompatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCompatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const 
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCompatComponent, EquippedWeapon);
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

////Firing Mechanism

//Called from local machine
void UCompatComponent::SetShouldFire(bool bShouldFire)
{	
	if(bShouldFire)
	{
		ServerFire();
	}
	else
	{
	}
}

//Called from server
void UCompatComponent::ServerFire_Implementation()
{
	MulticastFire();
}

//Called from server to execute in all machines
void UCompatComponent::MulticastFire_Implementation()
{
	if(EquippedWeapon) EquippedWeapon->Fire();
}






