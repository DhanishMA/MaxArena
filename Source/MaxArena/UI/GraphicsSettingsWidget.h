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
	UFUNCTION(BlueprintCallable)
	void WidgetSetup();

private:
	class UGameUserSettings*  GameUserSettings;

protected:
	
	UFUNCTION(BlueprintCallable)
	void ApplyGraphicsSettings();
	
	UFUNCTION(BlueprintCallable)
	void EnableHDR(bool value);
	
	UFUNCTION(BlueprintCallable)
	void EnableVSync(bool value);
	
	UFUNCTION(BlueprintCallable)
	void SetAntiAliasing(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetFrameRate(int value);
	
	UFUNCTION(BlueprintCallable)
	void SetOverallScalability(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetPostProcessing(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetShading(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetShadow(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetTexture(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetViewDistance(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void SetVisualEffects(int32 value);
	
	UFUNCTION(BlueprintCallable)
	void ValidateGaphicsSettings();

};
