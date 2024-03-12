// Ping Pong Online. All Rights Reserved.


#include "Core/PPOWall.h"

#include "Components/BoxComponent.h"

// Sets default values
APPOWall::APPOWall()
{
    PrimaryActorTick.bCanEverTick = false;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    RootComponent = Mesh;
    
    BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    BoxComponent->SetBoxExtent(FVector(13.0f, 100.0f, 50.0f));
    BoxComponent->SetCollisionProfileName("PhysicsActor");
    BoxComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APPOWall::BeginPlay()
{
    Super::BeginPlay();
}