// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PPOGameStateBase.generated.h"

UCLASS()
class PINGPONGONLINE_API APPOGameStateBase : public AGameStateBase
{
    GENERATED_BODY()

public:
    UPROPERTY(Replicated)
    int32 FirstPlayerScore = 0;

    UPROPERTY(Replicated)
    int32 SecondPlayerScore = 0;

protected:
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};