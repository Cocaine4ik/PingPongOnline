// Ping Pong Online. All Rights Reserved.


#include "Core/Player/PPOPlayerPawn.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APPOPlayerPawn::APPOPlayerPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    
    bReplicates = true;
    bAlwaysRelevant = true;
    
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    Mesh->SetCollisionProfileName(FName("PhysicsActor"));
    RootComponent = Mesh;

    BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    BoxComponent->SetBoxExtent(FVector(6.0f, 100.0f, 38.0f));
    BoxComponent->SetCollisionProfileName("Pawn");
    BoxComponent->SetupAttachment(RootComponent);
    
    SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    Camera->SetupAttachment(SpringArm);
    
    MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
    MovementComponent->MaxSpeed = 600.0f;
}


// Called when the game starts or when spawned
void APPOPlayerPawn::BeginPlay()
{
    Super::BeginPlay();

    SetReplicateMovement(true);
}

// Called every frame
void APPOPlayerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}



