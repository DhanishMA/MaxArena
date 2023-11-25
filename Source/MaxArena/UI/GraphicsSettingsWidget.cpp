// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphicsSettingsWidget.h"
#include "GameFramework/GameUserSettings.h"
#include "Math/UnrealMathUtility.h"
#include "Components/Button.h"

bool UGraphicsSettingsWidget::Initialize() 
{
    if(!Super::Initialize()) return false;

    GameUserSettings = GEngine->GetGameUserSettings();

    // IncreaseGraphics(SetAntiAliasing(4));

    return true;
}

// void UGraphicsSettingsWidget::IncreaseGraphics(TFunction<void(int value)> Function)
// {
    
// }

// // void UGraphicsSettingsWidget::DecreaseGraphics(TFunction<void(int value)> Function)
// // {

// // }

// // void UGraphicsSettingsWidget::GraphicsSwitch(TFunction<void(int value)> Function)
// {
    
// }

void UGraphicsSettingsWidget::ApplyGraphicsSettings()
{
    GameUserSettings->LoadSettings();
}

//Graphics property setters

void UGraphicsSettingsWidget::EnableHDR(bool value)
{
    GameUserSettings->EnableHDRDisplayOutput(value);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::EnableVSync(bool value)
{
    GameUserSettings->SetVSyncEnabled(value);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetAntiAliasing(int value)   
{
    value = FMath::Clamp(value,-1,1);
    AntiAliasingValue += value;
    AntiAliasingValue = FMath::Clamp(AntiAliasingValue, 0, 4);
    GameUserSettings->SetAntiAliasingQuality(AntiAliasingValue);
    UE_LOG(LogTemp, Warning, TEXT("AA----------: %d"), AntiAliasingValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetFrameRate(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetGlobalIllumination(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetOverallScalability(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetPostProcessing(int value)
{
    value = FMath::Clamp(value,-1,1);
    AntiAliasingValue += value;
    AntiAliasingValue = FMath::Clamp(AntiAliasingValue, 0, 4);
    GameUserSettings->SetPostProcessingQuality(AntiAliasingValue);
    UE_LOG(LogTemp, Warning, TEXT("AA----------: %d"), AntiAliasingValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetReflection(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetScreenResolution(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetShading(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetShadow(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetTexture(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetViewDistance(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetVisualEffects(int value)
{
    value = FMath::Clamp(value,-1,1);
    GameUserSettings;
    GameUserSettings->ApplySettings(true);
}


























































































































