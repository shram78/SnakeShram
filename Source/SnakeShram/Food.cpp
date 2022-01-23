
#include "Food.h"

AFood::AFood()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{

}

