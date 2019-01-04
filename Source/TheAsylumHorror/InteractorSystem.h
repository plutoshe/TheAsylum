// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractorSystem.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractor, const AActor*, hit);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEASYLUMHORROR_API UInteractorSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractorSystem();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(EditAnywhere)
	float Reach = 10000.f;

	FHitResult InteractableHit;
	UPROPERTY(BlueprintAssignable, Category = "interact")
	FInteractor interactItem;
};
