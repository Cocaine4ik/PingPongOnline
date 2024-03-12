// Ping Pong Online. All Rights Reserved.


#include "Core/Player/PPOPlayerController.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Net/UnrealNetwork.h"

APPOPlayerController::APPOPlayerController()
{
    bReplicates = true;
}

void APPOPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(APPOPlayerController, PlayerNum);
}

void APPOPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    
    InputComponent->BindAxis("MoveRight", this, &APPOPlayerController::MoveRight);
}

void APPOPlayerController::BeginPlay()
{
    Super::BeginPlay();
}

void APPOPlayerController::MoveRight(float AxisValue)
{
    if (AxisValue != 0.0f)
    {
        if (IsLocalController())
        {
            ServerMoveRight(AxisValue);
        }
    }
}

void APPOPlayerController::ServerMoveRight_Implementation(float AxisValue)
{
    if (APawn* ControlledPawn = GetPawn())
    {
        const auto MovementComponent = ControlledPawn->GetMovementComponent();
        if (!MovementComponent) return;
        
        float Speed = ControlledPawn->GetMovementComponent()->GetMaxSpeed();


        
        const FVector MoveDirection = ControlledPawn->GetActorRightVector() * AxisValue;
        const FVector NewLocation = ControlledPawn->GetActorLocation() + (MoveDirection * Speed *  GetWorld()->GetDeltaSeconds());

        bool bCanMoveRight = ControlledPawn->GetActorLocation().Y < 320.0f;
        bool bCanMoveLeft = ControlledPawn->GetActorLocation().Y > -320.0f;
        
        if ((AxisValue > 0 && bCanMoveRight) || (AxisValue < 0 && bCanMoveLeft))
        {
            FHitResult HitResult;
            ControlledPawn->SetActorLocation(NewLocation, true, &HitResult);
        }
    }
}

bool APPOPlayerController::ServerMoveRight_Validate(float AxisValue)
{
    return true;
}

void APPOPlayerController::SetPlayerNum_Implementation(EPlayerNum Num)
{
    PlayerNum = Num;
}

bool APPOPlayerController::SetPlayerNum_Validate(EPlayerNum Num)
{
    return true;
}
