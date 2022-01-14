
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.generated.h"

UCLASS()
class SNAKESHRAM_API ASnakeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
