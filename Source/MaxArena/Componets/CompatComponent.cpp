// Fill out your copyright notice in the Description page of Project Settings.


#include "CompatComponent.h"
#include "MaxArena/Weapon/Weapon.h"
#include "MaxArena/Character/Hero.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

UCompatComponent::UCompatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
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
	FHitResult HitResult;
	GetCrosshairHitResult(HitResult);
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

////

//Crosshair tracer
void UCompatComponent::GetCrosshairHitResult(FHitResult& CrosshairHitResult)
{
	FVector2D ViewportSize;
	if(GEngine && GEngine->GameViewport)
	{
		GEngine->GameViewport->GetViewportSize(ViewportSize);
	}
	FVector2D CrosshairPoss2d(ViewportSize.X /2.f, ViewportSize.Y /2.f);
	FVector CrosshairPosition; 
	FVector CrosshairDirection;
	bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0), CrosshairPoss2d, CrosshairPosition, CrosshairDirection);
	if(bScreenToWorld)
	{
		CrosshairHitResult;
		FVector Start = CrosshairPosition;
		FVector End = CrosshairPosition + CrosshairDirection * MaxTraceDistance;
		FCollisionQueryParams CrosshairQueryParams;
		CrosshairQueryParams.AddIgnoredActor(OwningCharacter);
		GetWorld()->LineTraceSingleByChannel(CrosshairHitResult, Start, End, ECollisionChannel::ECC_Visibility, CrosshairQueryParams);
		if(!CrosshairHitResult.bBlockingHit)
		{
			CrosshairHitResult.ImpactPoint = End;
		}
		else
		{
			DrawDebugSphere(GetWorld(), CrosshairHitResult.ImpactPoint, 16, 16, FColor::Red);
		}
	}
	
}


