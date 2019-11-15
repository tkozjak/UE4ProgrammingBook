// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFirstActor.h"

// Sets default values
AMyFirstActor::AMyFirstActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//adding ActorComponent subclass 
	actorStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	//load UStaticMesh asset from the disk and add its mesh (.Object) to UStaticMeshComponent
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object != nullptr) {
		actorStaticMesh->SetStaticMesh(meshAsset.Object);
	}
}

FString AMyFirstActor::toString() {
	return FString::Printf(TEXT("An instance of: %s"), *actorName);
}

// Called when the game starts or when spawned
void AMyFirstActor::BeginPlay()
{
	Super::BeginPlay();

	FString nameOfThisActor = this->GetName();	
	FString classOfThisActor = this->GetClass()->GetName();

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("Called from the Actor/BeginPlay. Name of the class: %s  Name of the object: %s"), *classOfThisActor, *nameOfThisActor) );
}

// Called every frame
void AMyFirstActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

