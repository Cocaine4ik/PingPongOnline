// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PPOScoreWidget.generated.h"

UCLASS()
class PINGPONGONLINE_API UPPOScoreWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "UI")
    FString GetFirstPlayerScoreUIText() const;

    UFUNCTION(BlueprintCallable, Category = "UI")
    FString GetSecondPlayerScoreUIText() const;
};