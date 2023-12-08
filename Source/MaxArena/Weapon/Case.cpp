// Fill out your copyright notice in the Description page of Project Settings.


#include "Case.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"

ACase::ACase()
{
	PrimaryActorTick.bCanEverTick = false;

	CaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CaseMesh"));
	SetRootComponent(CaseMesh);
	CaseMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	CaseMesh->SetSimulatePhysics(true);
	CaseMesh->SetEnableGravity(true);
	CaseMesh->SetNotifyRigidBodyCollision(true);
	CaseEjectionImpulse = 10.f;

}

void ACase::BeginPlay()
{
	Super::BeginPlay();
	CaseMesh->AddImpulse(GetActorForwardVector() * CaseEjectionImpulse);
	CaseMesh->OnComponentHit.AddDynamic(this, &ACase::OnHit);
}

void ACase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
	Destroy();
}

