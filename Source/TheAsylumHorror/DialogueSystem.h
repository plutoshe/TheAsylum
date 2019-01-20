// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DialogueSystem.generated.h"
USTRUCT(BlueprintType) //Blueprintable
struct FMyInterpStruct
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> key;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FString> value; //interping to
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDialogueSystemCancle);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueSystem, FString, text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueSystem1, TArray<FString>, text);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueSystem2, FMyInterpStruct, text);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDialogueSystem_Widget, FString, widgetName, FMyInterpStruct, updateContent);
// failed, no tmap
//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDialogueSystem1, TMap<FString, FString>, test1);

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
		FDialogueSystem2 TestStruct;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
		FDialogueSystem1 TestArray;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
		FDialogueSystemCancle Cancle;
	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
		FDialogueSystemCancle Test23;

	UPROPERTY(BlueprintAssignable, Category = "Dialogue")
		FDialogueSystem_Widget UpdateWidget;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	int current = 0;
	TArray<FString> text;
	TArray<FString> ss;
	TMap<FString, TArray<FString>> map;
	TMap<FString, FString> transit;
		
};
