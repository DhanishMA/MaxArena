// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	BoxCollisionComp =  CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	SetRootComponent(BoxCollisionComp);
	BoxCollisionComp->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxCollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxCollisionComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollisionComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	BoxCollisionComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	ProjectileMovementComp->bRotationFollowsVelocity = true;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	if(TracerParticle)
	{
		TracerParticleComp = UGameplayStatics::SpawnEmitterAttached(
			TracerParticle,
			BoxCollisionComp, 
			FName(), 
			GetActorLocation(), 
			GetActorRotation(), 
			EAttachLocation::KeepWorldPosition);
	}
	
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

