// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/BoxComponent.h"

AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxCollisionComp =  CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Box"));
	SetRootComponent(BoxCollisionComp);
	BoxCollisionComp->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	BoxCollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxCollisionComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	BoxCollisionComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	BoxCollisionComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic, ECollisionResponse::ECR_Block);

}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

