// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Case.generated.h"

UCLASS()
class MAXARENA_API ACase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CaseMesh;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* RootComp;
	UPROPERTY(VisibleAnywhere)
	class USoundCue* ImpactSound;

};
