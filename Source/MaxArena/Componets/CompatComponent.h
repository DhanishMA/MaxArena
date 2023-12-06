// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CompatComponent.generated.h"

#define MaxTraceDistance 8000.f

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAXARENA_API UCompatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UCompatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	friend class AHero;
	void EquipWeapon(class AWeapon* WeaponToEquip);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	FHitResult HitResult;
	virtual void BeginPlay() override;
	AHero* OwningCharacter;
	UPROPERTY(Replicated)
	AWeapon* EquippedWeapon;
	void SetShouldFire(bool bShouldFire);
	UFUNCTION(Server, Reliable)
	void ServerFire();
	UFUNCTION(NetMulticast, Reliable)
	void MulticastFire();
	void GetCrosshairHitResult(FHitResult& CrosshairHitResult);
		
};
