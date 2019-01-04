// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDialogueSystemCancle);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueSystem, FString, text);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEASYLUMHORROR_API UDialogueSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDialogueSystem();
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void Search(FString Type);
	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void Update();

	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
		FDialogueSystem TextChange;
	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
		FDialogueSystemCancle Cancle;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	int current = 0;
	TArray<FString> text;
		
};
