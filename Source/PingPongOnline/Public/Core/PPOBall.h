// Ping Pong Online. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPOBall.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class PINGPONGONLINE_API APPOBall : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APPOBall();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UStaticMeshComponent* Mesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USphereComponent* SphereComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement")
    float ReflectionPower = 600.0f;
    
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;


    virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

private:
    FVector InitialLocation;
    void LaunchBall();
    void Respawn();
};