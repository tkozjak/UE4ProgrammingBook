// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/World.h"
#include "UserProfile.h"
#include "MyFirstActor.h"
#include "ProgrammingBookGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAMMINGBOOK_API AProgrammingBookGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	FString m_actorName = "";
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UClassNames) TSubclassOf<UUserProfile> UPBlueprintClassName;

	void BeginPlay();
	
};
