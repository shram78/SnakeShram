
#include "SnakeElementBase.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"

ASnakeElementBase::ASnakeElementBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

}

void ASnakeElementBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASnakeElementBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

