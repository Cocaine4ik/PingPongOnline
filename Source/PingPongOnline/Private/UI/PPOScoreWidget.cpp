// Ping Pong Online. All Rights Reserved.


#include "UI/PPOScoreWidget.h"

#include "PPOGameStateBase.h"

FString UPPOScoreWidget::GetFirstPlayerScoreUIText() const
{
    FString ErrorString = TEXT("Error");

    if (!GetWorld())
    {
        return ErrorString;
    }

    if (const auto GameState = Cast<APPOGameStateBase>(GetWorld()->GetGameState()))
    {
        return FString::FromInt(GameState->FirstPlayerScore);
    }

    return ErrorString;
}

FString UPPOScoreWidget::GetSecondPlayerScoreUIText() const
{
    FString ErrorString = TEXT("Error");

    if (!GetWorld())
    {
        return ErrorString;
    }

    if (const auto GameState = Cast<APPOGameStateBase>(GetWorld()->GetGameState()))
    {
        return FString::FromInt(GameState->SecondPlayerScore);
    }

    return ErrorString;
}