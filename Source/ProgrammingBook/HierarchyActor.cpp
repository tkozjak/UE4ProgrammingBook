// Fill out your copyright notice in the Description page of Project Settings.


#include "HierarchyActor.h"

// Sets default values
AHierarchyActor::AHierarchyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rootSceneComponent = CreateDefaultSubobject<USceneComponent>("RootSceneComponenet");
	childSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponenet");

	RootComponent = rootSceneComponent;

	rootSphere = CreateDefaultSubobject<UStaticMeshComponent>("RootSphereMesh");
	childSphere = CreateDefaultSubobject<UStaticMeshComponent>("ChildSphereMesh");

	rootSphere->AttachTo(rootSceneComponent);
	childSphere->AttachTo(childSceneComponent);
	childSceneComponent->AttachTo(rootSceneComponent);

	auto staticMeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (staticMeshAsset.Object != nullptr) {
		rootSphere->SetStaticMesh(staticMeshAsset.Object);
		childSphere->SetStaticMesh(staticMeshAsset.Object);
	}

	childSceneComponent->SetRelativeLocation(FVector(0.0, 100.0, 0.0));

}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

