// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroController.h"
#include "Math/UnrealMathUtility.h"

AHeroController::AHeroController()
{

}

void AHeroController::BeginPlay()
{
	Super::BeginPlay();

    SwitchCharacter(0);
}

//Accept value from 0 to number of 'characters-1' and switch to respective character represented by this value
void AHeroController::SwitchCharacter(int index)
{   
    if (CharacterArray.Num() <= 0) return;
    int MaxArrSize = CharacterArray.Num();
    index = FMath::Clamp(index, 0, MaxArrSize - 1); 
    SpawnCharacter(&CharacterArray[index]);

}

void AHeroController::SpawnCharacter(TSubclassOf<ACharacter> *newCharacterClass)
{
    APawn* CurrentPawn = GetPawn();
    if (CurrentPawn == nullptr)
    {   
        
        FVector location = FVector(0,0,350);
        FRotator rotation = FRotator(0);
        ACharacter* newCharacter = GetWorld()->SpawnActor<ACharacter>(*newCharacterClass, location, rotation);
        if(newCharacter != nullptr) Possess(newCharacter);
    }
    
    else 
    {
        const FTransform SpawnTransform = CurrentPawn->GetActorTransform();
        UnPossess();
        ACharacter* newCharacter = GetWorld()->SpawnActor<ACharacter>(*newCharacterClass, SpawnTransform);
        if(newCharacter != nullptr) Possess(newCharacter);
    }
    
}

