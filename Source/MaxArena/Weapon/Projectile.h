// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class MAXARENA_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* BoxCollisionComp;
	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComp;
	class UParticleSystemComponent* TracerParticleComp;
	UPROPERTY(EditAnywhere)
	class UParticleSystem* TracerParticle; 

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactParticle;
	UPROPERTY(EditAnywhere)
	class USoundCue* ImpactSound;

};
