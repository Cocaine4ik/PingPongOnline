// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PPOCore.h"
#include "PPOPlayerController.generated.h"

UCLASS()
class PINGPONGONLINE_API APPOPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    APPOPlayerController();

    UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = "Player")
    EPlayerNum PlayerNum = EPlayerNum::NONE;

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
    virtual void SetupInputComponent() override;

    virtual void BeginPlay() override;

public:
    void MoveRight(float AxisValue);

    UFUNCTION(Server, Reliable, WithValidation)
    void ServerMoveRight(float AxisValue);
    void ServerMoveRight_Implementation(float AxisValue);
    bool ServerMoveRight_Validate(float AxisValue);
    
    UFUNCTION(Server, Reliable, WithValidation)
    void SetPlayerNum(EPlayerNum Num);
    void SetPlayerNum_Implementation(EPlayerNum Num);
    bool SetPlayerNum_Validate(EPlayerNum Num);
};