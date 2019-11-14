// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"
#include "MyFirstActor.generated.h"

UCLASS()
class PROGRAMMINGBOOK_API AMyFirstActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyFirstActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Properties) FString actorName;

	UPROPERTY() UStaticMeshComponent* actorStaticMesh;

	UFUNCTION(BlueprintCallable, Category = Properties) FString toString();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
