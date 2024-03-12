// Ping Pong Online. All Rights Reserved.


#include "Core/PPOGate.h"

#include "Components/BoxComponent.h"
#include "PPOGameModeBase.h"
#include "Core/PPOBall.h"

// Sets default values
APPOGate::APPOGate()
{
}

// Called when the game starts or when spawned
void APPOGate::BeginPlay()
{
    Super::BeginPlay();

    check(PlayerNum != EPlayerNum::NONE);
}

void APPOGate::AddScore()
{
    if (!GetWorld()) return;
    
    const auto GameMode = Cast<APPOGameModeBase>(GetWorld()->GetAuthGameMode());
    if (!GameMode) return;

    if (PlayerNum == EPlayerNum::FIRST)
    {
        GameMode->IncreaseSecondPlayerScore();
    }
    if (PlayerNum == EPlayerNum::SECOND)
    {
        GameMode->IncreaseFirstPlayerScore();
    }
}
