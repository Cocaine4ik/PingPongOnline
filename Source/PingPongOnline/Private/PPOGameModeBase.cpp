// Ping Pong Online. All Rights Reserved.


#include "PPOGameModeBase.h"
#include "Player/PPOPlayerPawn.h"
#include "Player/PPOPlayerController.h"
#include "UI/PPOGameHUD.h"
#include "EngineUtils.h"
#include "PPOGameStateBase.h"
#include "PPOPlayerStart.h"
#include "Net/UnrealNetwork.h"

APPOGameModeBase::APPOGameModeBase()
{
    DefaultPawnClass = APPOPlayerPawn::StaticClass();
    PlayerControllerClass = APPOPlayerController::StaticClass();
    HUDClass = APPOGameHUD::StaticClass();
    GameStateClass = APPOGameStateBase::StaticClass();

    bStartPlayersAsSpectators = true;
    bReplicates = true;
}

void APPOGameModeBase::IncreaseFirstPlayerScore_Implementation()
{
    const auto PPOGameState = GetGameState<APPOGameStateBase>();
    if (!PPOGameState) return;
    
    PPOGameState->FirstPlayerScore++;
}

bool APPOGameModeBase::IncreaseFirstPlayerScore_Validate()
{
    return true;
}

void APPOGameModeBase::IncreaseSecondPlayerScore_Implementation()
{
    const auto PPOGameState = GetGameState<APPOGameStateBase>();
    if (!PPOGameState) return;
    
    PPOGameState->SecondPlayerScore++;
}

bool APPOGameModeBase::IncreaseSecondPlayerScore_Validate()
{
    return true;
}

void APPOGameModeBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(APPOGameModeBase, FirstPlayerScore);
    DOREPLIFETIME(APPOGameModeBase, SecondPlayerScore);
}

void APPOGameModeBase::PreLogin(const FString& Options, const FString& Address, const TSharedPtr<const FUniqueNetId>& UniqueId,
    FString& ErrorMessage)
{

}

void APPOGameModeBase::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    const auto PlayerController = Cast<APPOPlayerController>(NewPlayer);
    
    NumberOfConnectedPlayers++;
    
    if (NumberOfConnectedPlayers == 2)
    {
        PlayerController->SetPlayerNum(EPlayerNum::SECOND);
        
        UE_LOG(LogTemp, Warning, TEXT("The second player has connected."));
        RestartPlayer(PlayerController);
    }
    else
    {
        PlayerController->SetPlayerNum(EPlayerNum::FIRST);
        
        UE_LOG(LogTemp, Warning, TEXT("Player connected. Total: %d"), NumberOfConnectedPlayers);
        RestartPlayer(PlayerController);
    }
}

AActor* APPOGameModeBase::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
    TArray<AActor*> PreferredStarts;
    
    for (TActorIterator<APPOPlayerStart> It(GetWorld()); It; ++It)
    {
        const auto PlayerStart = *It;
        const auto PlayerController = Cast<APPOPlayerController>(Player);
        
        if (PlayerController && PlayerStart->PlayerNum == PlayerController->PlayerNum)
        {
            UE_LOG(LogTemp, Warning, TEXT("SPAWN"));
            return PlayerStart;
        }
    }
    return Super::FindPlayerStart_Implementation(Player, IncomingName);
}
