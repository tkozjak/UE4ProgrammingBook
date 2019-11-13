// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROGRAMMINGBOOK_API UUserProfile : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats) float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats) float HpMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats) FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Unit)TSubclassOf<UObject> UClassOfPlayer;
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameModeBase", Category = Unit)) FStringClassReference UClassGameMode;
};
