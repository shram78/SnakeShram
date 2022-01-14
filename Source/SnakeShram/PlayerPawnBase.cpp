
#include "PlayerPawnBase.h"
#include "Engine/Classes/Camera/CameraComponent.h"

APlayerPawnBase::APlayerPawnBase()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;

}

void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

