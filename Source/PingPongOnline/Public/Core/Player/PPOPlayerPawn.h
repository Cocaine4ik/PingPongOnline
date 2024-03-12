// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PPOPlayerPawn.generated.h"

class UFloatingPawnMovement;
class USpringArmComponent;
class UCameraComponent;
class UBoxComponent;

UCLASS()
class PINGPONGONLINE_API APPOPlayerPawn : public APawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    APPOPlayerPawn();
    
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* Mesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UBoxComponent* BoxComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArm;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* Camera;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UFloatingPawnMovement* MovementComponent;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    
public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UStaticMeshComponent* GetMesh() const { return Mesh; }
};