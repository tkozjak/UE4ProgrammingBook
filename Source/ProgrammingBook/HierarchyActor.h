// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "HierarchyActor.generated.h"

UCLASS()
class PROGRAMMINGBOOK_API AHierarchyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHierarchyActor();

	UPROPERTY(VisibleAnywhere) USceneComponent* rootSceneComponent;
	UPROPERTY(VisibleAnywhere) USceneComponent* childSceneComponent;

	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* rootSphere;
	UPROPERTY(VisibleAnywhere) UStaticMeshComponent* childSphere;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
