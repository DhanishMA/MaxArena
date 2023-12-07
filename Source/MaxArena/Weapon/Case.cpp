// Fill out your copyright notice in the Description page of Project Settings.


#include "Case.h"
// #include "Components/SceneComponent.h"
#include "Sound/SoundCue.h"

ACase::ACase()
{
	PrimaryActorTick.bCanEverTick = false;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	SetRootComponent(RootComp);
	CaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CaseMesh"));
	CaseMesh->SetupAttachment(RootComp);
	ImpactSound = CreateDefaultSubobject<USoundCue>(TEXT("CaseImapctSound"));

}

void ACase::BeginPlay()
{
	Super::BeginPlay();
	
}

