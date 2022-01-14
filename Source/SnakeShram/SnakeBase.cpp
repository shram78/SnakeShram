
#include "SnakeBase.h"
#include "SnakeElementBase.h"

ASnakeBase::ASnakeBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, GetActorTransform());
	
}

void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

