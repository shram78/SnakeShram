
#include "SnakeBase.h"
#include "SnakeElementBase.h"

ASnakeBase::ASnakeBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ElementSize = 100.f;

}

void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();

	AddSnakeElement(4); // убрать магическое число
}

void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASnakeBase::AddSnakeElement(int ElementNum)
{
	for (int i = 0; i < ElementNum; ++i)
	{
		FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
		FTransform NewTransform(NewLocation);
		auto NewSnakeElement = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
		SnakeElements.Add(NewSnakeElement);
	}
}