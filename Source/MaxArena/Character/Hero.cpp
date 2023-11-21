// Fill out your copyright notice in the Description page of Project Settings.


#include "Hero.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AHero::AHero()
{
	PrimaryActorTick.bCanEverTick = true;

	TPPSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPPSpringArm"));
	TPPSpringArm->SetupAttachment(RootComponent);
	TPPSpringArm->bUsePawnControlRotation = true;

	TPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPPCamera"));
	TPPCamera->SetupAttachment(TPPSpringArm);
	
	
}

void AHero::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHero::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump",IE_Pressed , this, &ACharacter::Jump);
	// PlayerInputComponent->BindAction("Crouch",IE_Pressed , this, &ACharacter::Crouch);

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



