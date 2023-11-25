// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GraphicsSettingsWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAXARENA_API UGraphicsSettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual bool Initialize() override;

public:
	class UGameUserSettings*  GameUserSettings;
	UFUNCTION(BlueprintCallable)
	void ApplyGraphicsSettings();

	int AntiAliasingValue  = 3;


public:
	// void IncreaseGraphics(TFunction<void(int value)> Function);
	// void DecreaseGraphics(TFunction<void(int value)> Function);
	// void GraphicsSwitch(TFunction<void(int value)> Function);


	void EnableHDR(bool value);
	void EnableVSync(bool value);
	UFUNCTION(BlueprintCallable)
	void SetAntiAliasing(int value);
	void SetFrameRate(int value);
	UFUNCTION(BlueprintCallable)
	void SetGlobalIllumination(int value);
	void SetOverallScalability(int value);
	UFUNCTION(BlueprintCallable)
	void SetPostProcessing(int value);
	UFUNCTION(BlueprintCallable)
	void SetReflection(int value);
	UFUNCTION(BlueprintCallable)
	void SetScreenResolution(int value);
	void SetShading(int value);
	void SetShadow(int value);
	void SetTexture(int value);
	void SetViewDistance(int value);
	void SetVisualEffects(int value);

};
