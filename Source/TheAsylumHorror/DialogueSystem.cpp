// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueSystem.h"

// Sets default values for this component's properties
UDialogueSystem::UDialogueSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UDialogueSystem::Search(FString Type) {
	text = map[Type];
	current = 0;
}

void UDialogueSystem::Update() {
	if (current >= text.Num()) {
		Cancle.Broadcast();
	}
	else {
		TextChange.Broadcast(text[current]);
	}
		current++;
}

// Called when the game starts
void UDialogueSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FString g[] = { TEXT("1"), TEXT("2"), TEXT("3") };
	text.Empty();
	text.Append(g, ARRAY_COUNT(g));
	map.Add("test1", text);
	text[0] = TEXT("test2_0");
	text[1] = TEXT("test2_1");
	text.Add("333");
	map.Add("test2", text);
}


// Called every frame
void UDialogueSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

