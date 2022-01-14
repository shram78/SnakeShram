#include "SnakeBase.h"
#include "SnakeElementBase.h"

ASnakeBase::ASnakeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ElementSize = 100.f;
	MovementSpeed = 10.f;
	LastMoveDirection = EMovementDirection::UP;
}

void ASnakeBase::BeginPlay()
{
	int StartElementSnake = 5;
	Super::BeginPlay();
	SetActorTickInterval(MovementSpeed);

	AddSnakeElement(StartElementSnake);
}

void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void ASnakeBase::AddSnakeElement(int ElementNum)
{
	for (int i = 0; i < ElementNum; ++i)
	{
		FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
		FTransform NewTransform(NewLocation);
		ASnakeElementBase* NewSnakeElement = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
		SnakeElements.Add(NewSnakeElement);
	}
}

void ASnakeBase::Move()
{
	FVector MovementVector;
	float MovemenSpeed = ElementSize;

	switch (LastMoveDirection)
	{
	case EMovementDirection::UP:
		MovementVector.X += MovemenSpeed;
		break;
	case EMovementDirection::DOWN:
		MovementVector.X -= MovemenSpeed;
		break;
	case EMovementDirection::LEFT:
		MovementVector.Y += MovemenSpeed;
		break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= MovemenSpeed;
		break;
	}

	//AddActorWorldOffset(MovementVector);

	for (int i = SnakeElements.Num() - 1; i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PreviousElement = SnakeElements[i - 1];
		FVector PreviousLocation = PreviousElement->GetActorLocation();
		CurrentElement->SetActorLocation(PreviousLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
}