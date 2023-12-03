// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Hero.generated.h"

UCLASS()
class MAXARENA_API AHero : public ACharacter
{
	GENERATED_BODY()

public:
	AHero();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;
	void SetOverlappedWeapon(class AWeapon* Weapon);
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(ReplicatedUsing = OnRep_OverlappedWeapon)
	class AWeapon* OverlappedWeapon;
	UFUNCTION()
	void OnRep_OverlappedWeapon(class AWeapon* LastWeapon);
	UPROPERTY(EditDefaultsOnly, Category = Camera)
	class UCameraComponent* TPPCamera;
	UPROPERTY(EditDefaultsOnly, Category = Camera)
	class USpringArmComponent* TPPSpringArm;
	UPROPERTY(EditDefaultsOnly)
	class UCompatComponent* CompatComponent;

	void MoveForward(float value);
	void MoveRitght(float value);
	void EquipButtonPressed();
	void FireButtonPressed();
	void FireButtonReleased();

	UFUNCTION(Server, Reliable)
	void ServerEquipButtonPressed();

};
