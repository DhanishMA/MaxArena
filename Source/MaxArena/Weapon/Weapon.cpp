// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "MaxArena/Character/Hero.h"
#include "Net/UnrealNetwork.h"
#include "Animation/AnimationAsset.h"
#include "Components/SkeletalMeshComponent.h"

AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisonSphere"));
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(RootComponent);

}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
	if(HasAuthority())
	{
		CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		CollisionSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);
		CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnSphereOverlap);
		CollisionSphere->OnComponentEndOverlap.AddDynamic(this, &AWeapon::OnSphereEndOverlap);
	}
	if(PickupWidget) PickupWidget->SetVisibility(false);
}

void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AWeapon, WeaponState);
}

////Sphere collision interaction functions

void AWeapon::OnSphereOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(AHero* OverlappedPawn = Cast<AHero>(OtherActor)) OverlappedPawn->SetOverlappedWeapon(this);
}
	
void AWeapon::OnSphereEndOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if(AHero* OverlappedPawn = Cast<AHero>(OtherActor)) OverlappedPawn->SetOverlappedWeapon(nullptr);
}

////

////Fire mechanism
void AWeapon::Fire(const FVector& TraceHitLocation)
{	
	if(FireAnimation && WeaponMesh) WeaponMesh->PlayAnimation(FireAnimation, false);
}


void AWeapon::SetPickupWidgerVisibility(bool bSetVisibility)
{
	if(PickupWidget != nullptr) PickupWidget->SetVisibility(bSetVisibility);
}

void AWeapon::SetWeaponState(EWeaponState State)
{
	WeaponState = State;
	switch(WeaponState)
	{
		case EWeaponState::EWS_Equipped :
			SetPickupWidgerVisibility(false);
			CollisionSphere->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AWeapon::OnRep_WeaponState()
{
	switch(WeaponState)
	{
		case EWeaponState::EWS_Equipped :
			SetPickupWidgerVisibility(false);
	}
}










