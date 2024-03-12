// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EPlayerNum : uint8
{
    NONE UMETA(DisplayName = "NONE"),
    FIRST UMETA(DisplayName = "FIRST"),
    SECOND UMETA(DisplayName = "SECOND"),
};