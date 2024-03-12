// Ping Pong Online. All Rights Reserved.


#include "Core/PPOBall.h"

#include "PPOGate.h"
#include "PPOPlayerPawn.h"
#include "Components/SphereComponent.h"

// Sets default values
APPOBall::APPOBall()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    bReplicates = true;

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    Mesh->SetSimulatePhysics(true);
    Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Mesh->SetEnableGravity(false);
    Mesh->SetConstraintMode(EDOFMode::XYPlane);
    RootComponent = Mesh;

    SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereCollision");
    SphereComponent->SetCollisionProfileName("Trigger");
    SphereComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APPOBall::BeginPlay()
{
    Super::BeginPlay();

    SetReplicateMovement(true);

    InitialLocation = GetActorLocation();

    LaunchBall();
}

void APPOBall::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation,
    FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

    // GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Hit");

    if (!Other)
    {
        return;
    }

    // Handle hit with Gate
    if (const auto Gate = Cast<APPOGate>(Other))
    {
        Gate->AddScore();
        Respawn();
    }

    // Calculate reflection based on hit normal
    const FVector ReflectionVector = FMath::GetReflectionVector(Mesh->GetPhysicsLinearVelocity(), HitNormal);
    FVector NewBallVelocity;

    if (const auto PlayerPawn = Cast<APPOPlayerPawn>(Other))
    {
        // Hit with PlayerPawn
        const FVector PaddleLinearVelocity = PlayerPawn->GetMesh()->GetPhysicsLinearVelocity();
        NewBallVelocity = PaddleLinearVelocity.GetSafeNormal() - ReflectionVector.GetSafeNormal();
    }
    else
    {
        // Default reflection for other objects
        NewBallVelocity = ReflectionVector;
    }

    Mesh->SetPhysicsLinearVelocity(NewBallVelocity.GetSafeNormal() * ReflectionPower);
}


void APPOBall::LaunchBall()
{
    Mesh->
        SetPhysicsLinearVelocity(FVector((FMath::RandBool() ? 1.f : -1.f) * ReflectionPower,
            (FMath::RandBool() ? 1.f : -1.f) * ReflectionPower,
            0.f));
}

void APPOBall::Respawn()
{
    SetActorLocation(InitialLocation);

    LaunchBall();
}