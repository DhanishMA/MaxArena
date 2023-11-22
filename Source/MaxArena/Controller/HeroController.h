// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "HeroController.generated.h"

/**
 * 
 */
UCLASS()
class MAXARENA_API AHeroController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AHeroController();
	UFUNCTION(BlueprintCallable)
	int SwitchCharacter(int index);

protected:
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<ACharacter>> CharacterArray;
	virtual void BeginPlay() override;

	void SpawnCharacter(TSubclassOf<ACharacter> *newCharacterClass);
};
