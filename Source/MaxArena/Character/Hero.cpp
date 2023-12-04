// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "MaxArena/Weapon/Weapon.h"
#include "Net/UnrealNetwork.h"
#include "MaxArena/Componets/CompatComponent.h"
#include "Components/CapsuleComponent.h"

AHero::AHero()
{
	PrimaryActorTick.bCanEverTick = true;

	TPPSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPPSpringArm"));
	TPPSpringArm->SetupAttachment(RootComponent);
	TPPSpringArm->bUsePawnControlRotation = true;

	TPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPPCamera"));
	TPPCamera->SetupAttachment(TPPSpringArm);
	CompatComponent = CreateDefaultSubobject<UCompatComponent>(TEXT("CompatComponent"));
	if(UCapsuleComponent* CapsuleComp = GetCapsuleComponent())
	{
		CapsuleComp->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	}
	
}

void AHero::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHero::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	
	CompatComponent->SetIsReplicated(true);
	CompatComponent->OwningCharacter = this;
}

void AHero::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(AHero, OverlappedWeapon, COND_OwnerOnly);
}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump",IE_Pressed , this, &ACharacter::Jump);
	// PlayerInputComponent->BindAction("Crouch",IE_Pressed , this, &ACharacter::Crouch);
	PlayerInputComponent->BindAction("EquipeWeapon", IE_Pressed, this, &AHero::EquipButtonPressed);
	PlayerInputComponent->BindAction("FireButton", IE_Pressed, this, &AHero::FireButtonPressed);
	PlayerInputComponent->BindAction("FireButton", IE_Released, this, &AHero::FireButtonReleased);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHero::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHero::MoveRitght);
	PlayerInputComponent->BindAxis("LookUp", this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ACharacter::AddControllerYawInput);


}


//Input Functions

void AHero::MoveForward(float value)
{
	FVector ForwardVector = GetActorForwardVector();
	ACharacter::AddMovementInput(ForwardVector, value);
}

void AHero::MoveRitght(float value)
{
	FVector RightVector = GetActorRightVector();
	ACharacter::AddMovementInput(RightVector, value);
}

void AHero::EquipButtonPressed()
{	
	if(HasAuthority())
	{
		if(CompatComponent) CompatComponent->EquipWeapon(OverlappedWeapon);
	}

	else ServerEquipButtonPressed();
}

void AHero::FireButtonPressed()
{
	if(CompatComponent) CompatComponent->SetShouldFire(true);
}

void AHero::FireButtonReleased()
{
	if(CompatComponent) CompatComponent->SetShouldFire(false);
}

//Weapon handiling fuctions

void AHero::SetOverlappedWeapon(AWeapon* Weapon)
{
	if(IsLocallyControlled()) 
	{
		if(OverlappedWeapon) OverlappedWeapon->SetPickupWidgerVisibility(false);
		if(Weapon) Weapon->SetPickupWidgerVisibility(true);
	}
	OverlappedWeapon = Weapon;
}

void AHero::OnRep_OverlappedWeapon(AWeapon* LastWeapon)
{
	if(OverlappedWeapon) OverlappedWeapon->SetPickupWidgerVisibility(true);
	if(LastWeapon != nullptr) LastWeapon->SetPickupWidgerVisibility(false);
}

void AHero::ServerEquipButtonPressed_Implementation()
{
	if(CompatComponent) CompatComponent->EquipWeapon(OverlappedWeapon);
}



