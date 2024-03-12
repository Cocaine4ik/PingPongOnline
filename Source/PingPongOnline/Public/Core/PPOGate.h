// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PPOWall.h"
#include "PPOCore.h"
#include "PPOGate.generated.h"


UCLASS()
class PINGPONGONLINE_API APPOGate : public APPOWall
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APPOGate();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Player")
    EPlayerNum PlayerNum = EPlayerNum::NONE;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    void AddScore();
};
