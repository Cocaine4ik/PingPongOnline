// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPOWall.generated.h"

class UBoxComponent;

UCLASS()
class PINGPONGONLINE_API APPOWall : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APPOWall();

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* Mesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* BoxComponent;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

};