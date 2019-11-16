// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"
#include "SelfReplicator.generated.h"

UCLASS()
class PROGRAMMINGBOOK_API ASelfReplicator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASelfReplicator();

	UPROPERTY(VisibleAnywhere) USceneComponent* rootSceneComponent;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* staticMeshComponent;

private:
	UFUNCTION() void incrementReplicaCount();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
