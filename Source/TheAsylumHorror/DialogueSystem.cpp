// Fill out your copyright notice in the Description page of Project Settings.

#include "DialogueSystem.h"
#include "Misc/FileHelper.h"

// Sets default values for this component's properties
UDialogueSystem::UDialogueSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UDialogueSystem::Search(FString Type) {
	if (map.Contains(Type)) {
		text = map[Type];
		current = 0;
	}
	else {
		text.Empty();
		current = 0;
	}
}

void UDialogueSystem::Update() {
	if (current >= text.Num()) {
		Cancle.Broadcast();
	}
	else {
		FString WidgetName = "";
		TArray<FString> trans;
		TArray<FString> keys, values;
		text[current].ParseIntoArray(trans, TEXT(","), true);
		keys.Empty();
		values.Empty();
		for (int i = 0; i < trans.Num(); i++) {
			TArray<FString> kvpair;
			trans[i].ParseIntoArray(kvpair, TEXT(":"), true);
			if (kvpair.Num() >= 2) {
				if (kvpair[0].ToUpper() == "WIDGET") {
					WidgetName = kvpair[1];
				}
				keys.Add(kvpair[0]);
				values.Add(kvpair[1]);
			}
		}
		UpdateWidget.Broadcast(WidgetName, FMyInterpStruct{ keys, values });
	}
	current++;
	
}

// Called when the game starts
void UDialogueSystem::BeginPlay()
{
	Super::BeginPlay();
	FString saveText;
	FFileHelper::LoadFileToString(saveText, *(FPaths::GameDir() + "test.txt"));
	TArray<FString> Out;
	text.Empty();
	TArray<FString> trans;
	saveText.ParseIntoArray(Out, TEXT("- "), true);
	for (int i = 0; i < Out.Num(); i++) {
		Out[i] = Out[i].Replace(ANSI_TO_TCHAR("\n"), ANSI_TO_TCHAR(""));
		Out[i] = Out[i].Replace(ANSI_TO_TCHAR("\r"), ANSI_TO_TCHAR(""));
		Out[i].ParseIntoArray(trans, TEXT("# "), true);
		for (int j = 0; j < trans.Num(); j++) {
			UE_LOG(LogTemp, Log, TEXT("%d: %s"), j, *trans[j]);
		}
		if (trans.Num() > 0) {
			FString key = trans[0];
			trans.RemoveAt(0);
			UE_LOG(LogTemp, Log, TEXT("#%s#"), *key);
			map.Add(key, trans);
		}
	}

}


// Called every frame
void UDialogueSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

