// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PPOGameHUD.generated.h"

class UUserWidget;

UCLASS()
class PINGPONGONLINE_API APPOGameHUD : public AHUD
{
    GENERATED_BODY()

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerScoreWidgetClass;

    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UUserWidget* PlayerScoreWidget;
};