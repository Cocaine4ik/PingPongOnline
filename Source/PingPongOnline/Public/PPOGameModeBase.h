// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PPOGameModeBase.generated.h"

UCLASS()
class PINGPONGONLINE_API APPOGameModeBase : public AGameModeBase
{
    GENERATED_BODY()

public:
    APPOGameModeBase();

    UFUNCTION(Server, Reliable, WithValidation)
    void IncreaseFirstPlayerScore();
    void IncreaseFirstPlayerScore_Implementation();
    bool IncreaseFirstPlayerScore_Validate();
    
    UFUNCTION(Server, Reliable, WithValidation)
    void IncreaseSecondPlayerScore();
    void IncreaseSeondPlayerScore_Implementation();
    bool IncreaseSecondPlayerScore_Validate();

    UPROPERTY(Replicated)
    int32 FirstPlayerScore = 0;
    UPROPERTY(Replicated)
    int32 SecondPlayerScore = 0;
    

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
protected:
    // Overrides to control behaviour when new players join the game (both locally and over the network)
    virtual void PreLogin(const FString & Options, const FString & Address, const TSharedPtr < const FUniqueNetId > & UniqueId, FString & ErrorMessage);
    virtual void PostLogin(APlayerController * NewPlayer) override;

    virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;
private:
    
    int32 NumberOfConnectedPlayers = 0;

    
};

