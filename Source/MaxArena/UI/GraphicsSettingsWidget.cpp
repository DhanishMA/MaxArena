// Fill out your copyright notice in the Description page of Project Settings.


#include "GraphicsSettingsWidget.h"
#include "GameFramework/GameUserSettings.h"
#include "Math/UnrealMathUtility.h"
#include "Components/Button.h"

bool UGraphicsSettingsWidget::Initialize() 
{
    if(!Super::Initialize()) return false;

    GameUserSettings = GEngine->GetGameUserSettings();

    return true;
}

void UGraphicsSettingsWidget::WidgetSetup()
{
    AddToViewport();
    SetVisibility(ESlateVisibility::Visible);
    bIsFocusable = true;

    if(UWorld* World = GetWorld())
    {
        if (APlayerController* Controller = World->GetFirstPlayerController())
        {
            FInputModeUIOnly InputMode;
            InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
            InputMode.SetWidgetToFocus(TakeWidget());
            Controller->SetInputMode(InputMode);
            Controller->SetShowMouseCursor(true);
        }
        
    }
}


//Graphics property setters

void UGraphicsSettingsWidget::ValidateGaphicsSettings()
{
    GameUserSettings->ValidateSettings();
}

void UGraphicsSettingsWidget::ApplyGraphicsSettings()
{
    GameUserSettings->LoadSettings();
}

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

void UGraphicsSettingsWidget::SetAntiAliasing(int32 value)   
{
    int InValue = GameUserSettings->GetAntiAliasingQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetAntiAliasingQuality(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetFrameRate(int value)
{
    float InValue = GameUserSettings->GetFrameRateLimit();
    value = FMath::Clamp(value, -1, 1);
    InValue = InValue + (value > 0 ? 30.f : -30.f);
    GameUserSettings->SetFrameRateLimit(InValue);
    InValue = FMath::Clamp(InValue, 0.f, 120.f);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetOverallScalability(int32 value)
{
    int32 InValue = GameUserSettings->GetOverallScalabilityLevel();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetOverallScalabilityLevel(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetPostProcessing(int32 value)
{
    int32 InValue = GameUserSettings->GetPostProcessingQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetPostProcessingQuality(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetShading(int32 value)
{
    int InValue = GameUserSettings->GetShadingQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetShadingQuality(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetShadow(int32 value)
{
    int InValue = GameUserSettings->GetShadingQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetShadowQuality(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetTexture(int32 value)
{
    int InValue = GameUserSettings->GetTextureQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetTextureQuality(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetViewDistance(int32 value)
{
    int InValue = GameUserSettings->GetViewDistanceQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetViewDistanceQuality(InValue);
    GameUserSettings->ApplySettings(true);
}

void UGraphicsSettingsWidget::SetVisualEffects(int32 value)
{
    int InValue = GameUserSettings->GetVisualEffectQuality();
    InValue = InValue + (FMath::Clamp(value, -1, 1));
    GameUserSettings->SetVisualEffectQuality(InValue);
    GameUserSettings->ApplySettings(true);
}























































































































