// Ping Pong Online. All Rights Reserved.


#include "PPOGameStateBase.h"
#include "Net/UnrealNetwork.h"

void APPOGameStateBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(APPOGameStateBase, FirstPlayerScore);
    DOREPLIFETIME(APPOGameStateBase, SecondPlayerScore);
}