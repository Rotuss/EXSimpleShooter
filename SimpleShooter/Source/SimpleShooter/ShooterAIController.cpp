// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

void AShooterAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	//APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//MoveToActor(PlayerPawn, 200);

	//if (true == LineOfSightTo(PlayerPawn))
	//{
	//	//SetFocus(PlayerPawn);
	//	//MoveToActor(PlayerPawn, AcceptanceRadius);

	//	GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
	//	GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
	//}
	//else
	//{
	//	//ClearFocus(EAIFocusPriority::Gameplay);
	//	//StopMovement();

	//	GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
	//}
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (nullptr != ControlledCharacter)
	{
		return ControlledCharacter->IsDead();
	}
	
	return true;
}

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	//SetFocus(PlayerPawn);

	if (nullptr != AIBehavior)
	{
		RunBehaviorTree(AIBehavior);

		//GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		//GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnowPlayerLocation"), GetPawn()->GetActorLocation());
	}

}
