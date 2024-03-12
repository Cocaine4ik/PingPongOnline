// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerStart.h"
#include "PPOCore.h"
#include "PPOPlayerStart.generated.h"

/**
 * 
 */
UCLASS()
class PINGPONGONLINE_API APPOPlayerStart : public APlayerStart
{
    GENERATED_BODY()

public:
    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Player")
    EPlayerNum PlayerNum = EPlayerNum::NONE;
};