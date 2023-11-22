// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroController.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/GameModeBase.h"

AHeroController::AHeroController()
{

}

void AHeroController::BeginPlay()
{
	Super::BeginPlay();

    SwitchCharacter(0);
}

//Accept value from 0 to number of 'characters-1' and switch to respective character represented by this value. The function returns the value 
//of the new characters index
int AHeroController::SwitchCharacter(int index)
{   
    if (CharacterArray.Num() <= 0) return 0;
    int MaxArrSize = CharacterArray.Num();
    index = FMath::Clamp(index, 0, MaxArrSize-1); 
    UE_LOG(LogTemp, Warning, TEXT("Character Array Index %d"), index);
    UE_LOG(LogTemp, Warning, TEXT("MaxArrSize %d"), MaxArrSize);
    SpawnCharacter(&CharacterArray[index]);

    return index;

}

void AHeroController::SpawnCharacter(TSubclassOf<ACharacter> *newCharacterClass)
{
    APawn* CurrentPawn = GetPawn();
    if (CurrentPawn == nullptr)
    {   
        AGameModeBase* GameModeBase = GetWorld()->GetAuthGameMode();
        if(GameModeBase == nullptr) return;
        AActor* PlayerStart = GameModeBase->ChoosePlayerStart(this);
        if(PlayerStart == nullptr) return;
        const FTransform ControllerSpawnTransform = PlayerStart->GetActorTransform();
        ACharacter* newCharacter = GetWorld()->SpawnActor<ACharacter>(*newCharacterClass, ControllerSpawnTransform);
        if(newCharacter != nullptr) Possess(newCharacter);
    }
    
    else 
    {
        const FTransform SpawnTransform = CurrentPawn->GetActorTransform();
        UnPossess();
        CurrentPawn->Destroy();
        ACharacter* newCharacter = GetWorld()->SpawnActor<ACharacter>(*newCharacterClass, SpawnTransform);
        if(newCharacter != nullptr) Possess(newCharacter);
    }
    
}

