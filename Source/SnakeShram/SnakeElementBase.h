#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeElementBase.generated.h"

class UStaticMeshComponent;

UCLASS()
class SNAKESHRAM_API ASnakeElementBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeElementBase();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent)
	void SetFirstElementType();
	void SetFirstElementType_Implementation();
};
