// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//adding subcomponent
	actorStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
}

FString AMyFirstActor::toString() {
	return FString::Printf(TEXT("An instance of: %s"), *actorName);
}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();

	FString thisActorName = this->GetName();
		
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor spawned"));
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

