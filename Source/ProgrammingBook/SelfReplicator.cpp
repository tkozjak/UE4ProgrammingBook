// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfReplicator.h"

// Sets default values
ASelfReplicator::ASelfReplicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("RootStaticMesh");
	rootSceneComponent = CreateDefaultSubobject<USceneComponent>("Root");

	
	RootComponent = rootSceneComponent;	
	staticMeshComponent->AttachTo(rootSceneComponent);

	auto staticMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (staticMeshAsset.Object != nullptr) {
		staticMeshComponent->SetStaticMesh(staticMeshAsset.Object);
	}


}

void ASelfReplicator::incrementReplicaCount() {
	
	static int replicaCount = 0;

	replicaCount += 1;

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("Repica count: %i"), replicaCount));
	if (replicaCount<20) {
		auto actorSpawnLocation = this->GetTargetLocation() + FVector(50 * FMath::FRandRange(-1, 1), 50 * FMath::FRandRange(-1, 1), 50 * FMath::FRandRange(-1, 1));
		UWorld* world = this->GetWorld();
		world->SpawnActor(ASelfReplicator::StaticClass(), &actorSpawnLocation);
	}
}

// Called when the game starts or when spawned
void ASelfReplicator::BeginPlay()
{
	Super::BeginPlay();

	incrementReplicaCount();	
}

// Called every frame
void ASelfReplicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

