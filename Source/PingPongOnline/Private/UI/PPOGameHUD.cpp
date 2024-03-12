// Ping Pong Online. All Rights Reserved.


#include "UI/PPOGameHUD.h"
#include "Blueprint/UserWidget.h"

void APPOGameHUD::BeginPlay()
{
    Super::BeginPlay();

    check(PlayerScoreWidgetClass)
    
    PlayerScoreWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerScoreWidgetClass);

    PlayerScoreWidget->AddToViewport();
    PlayerScoreWidget->SetVisibility(ESlateVisibility::Visible);
}