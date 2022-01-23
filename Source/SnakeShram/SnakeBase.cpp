#include "SnakeBase.h"
#include "SnakeElementBase.h"
#include "Interactable.h"

ASnakeBase::ASnakeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ElementSize = 100.0f;
	MovementSpeed = 10.0f;
	LastMoveDirection = EMovementDirection::DOWN;
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
		NewSnakeElement->SnakeOwner = this;
		int32 ElementIndex = SnakeElements.Add(NewSnakeElement);

		if (ElementIndex == 0)
		{
			NewSnakeElement->SetFirstElementType();
		}
	}
}

void ASnakeBase::Move()
{
	FVector MovementVector(ForceInitToZero);

	switch (LastMoveDirection)
	{
	case EMovementDirection::UP:
		MovementVector.X += ElementSize;
		break;
	case EMovementDirection::DOWN:
		MovementVector.X -= ElementSize;
		break;
	case EMovementDirection::LEFT:
		MovementVector.Y += ElementSize;
		break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= ElementSize;
		break;
	}

	for (int i = SnakeElements.Num() - 1; i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PreviousElement = SnakeElements[i - 1];
		FVector PreviousLocation = PreviousElement->GetActorLocation();
		CurrentElement->SetActorLocation(PreviousLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
}

void ASnakeBase::SnakeElementOverlap(ASnakeElementBase* OverlappedElement, AActor* Other)
{
	if (IsValid(OverlappedElement))
	{
		int32 ElemIndex;
		SnakeElements.Find(OverlappedElement, ElemIndex);
		bool bIsFirst = ElemIndex == 0;

		IInteractable* InteractableInterface = Cast<IInteractable>(Other);
		if (InteractableInterface)
		{
			  InteractableInterface->Interact(this, bIsFirst);
		}
	}
}
