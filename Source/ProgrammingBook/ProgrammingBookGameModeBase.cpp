// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgrammingBookGameModeBase.h"

void AProgrammingBookGameModeBase::BeginPlay() {
	Super::BeginPlay();

	m_actorName = GetName();
	
	UE_LOG(LogTemp, Warning, TEXT("The Name of The Actor: %s"), *m_actorName);
	
	//constructing a blueprint class object (derived from a C++ class) with C++
	UUserProfile* userProfile = NewObject<UUserProfile>( this, UPBlueprintClassName.Get());
	
	if (IsValid(userProfile)){
		UE_LOG(LogTemp, Warning, TEXT("UserProfile instantiated!"));

		UObject* transientPackage = (UObject*)GetTransientPackage();
		UClass* transientPackageClass = transientPackage->StaticClass();

		// get the name of the transient package's class
		FString tpname = transientPackageClass->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the transient package's class: %s"), *tpname);

		// get the class name of this object
		FString thisClassName = this->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The class name of this object: %s"), *thisClassName);
		
		// get the class name of this object's Outer object
		FString thisClassOuterName = this->GetOuter()->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The the class name of this object's Outer object: %s"), *thisClassOuterName);
		
		// get the class name of this objects's outer's outer
		FString thisClassOuterOuterName = this->GetOuter()->GetOuter()->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("the class name of this objects's Outer's Outer: %s"), *thisClassOuterOuterName);
		

		// get the class name of this object's super class
		FString thisClassSuperName = this->GetClass()->GetSuperClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The class name of this object's super class: %s"), *thisClassSuperName);
		
		// get the class name of this object's super's super class
		FString thisClassSuperSuperName = this->GetClass()->GetSuperClass()->GetSuperClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The class name of this object's super's super class: %s"), *thisClassSuperSuperName);
		
		// get the name of the class of userprofile object
		FString userProfileObject_ClassName = userProfile->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The class name of UserProfile object is: %s"), *userProfileObject_ClassName);
		
		// get the name of the class of userprofile object' outer
		FString userProfileObject_OuterClassName = userProfile->GetOuter()->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the class of userprofile object' outer: %s"), *userProfileObject_OuterClassName);


		/*
		// get the name of the class selected from drop down menu
		FString ddClassName = UPBlueprintClassName->GetDefaultObject()->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the class selected from DD menu: %s"), *ddClassName);

		// get the name of the class selected from drop down menu via Get() method
		FString ddClassNameViaGet = UPBlueprintClassName.Get()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the class selected from DD menu via Get() method: %s"), *ddClassNameViaGet);

		// get the name of the class selected from drop down menu's Outer via Get() method
		FString ddOuterClassNameViaGet = UPBlueprintClassName.Get()->GetOuter()->GetClass()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of the class selected from DD menu via Get() method Super: %s"), *ddOuterClassNameViaGet);


		/// get the name of this class via CDO 
		FString thisClassCDOName = this->GetClass()->GetDefaultObject()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The name of this class' CDO object: %s"), *thisClassCDOName)
			*/

	}

	//SPAWNING ACTOR
	FTransform actorSpawnLoacation;
	actorSpawnLoacation.SetTranslation(FVector(0.0, 0.0, 250.0));
	UWorld* world = this->GetWorld();
	FString worldName = world->GetName();
	UE_LOG(LogTemp, Warning, TEXT("Called from GameMode/BeginPlay. The name of the world: %s"), *worldName);
	world->SpawnActor<AMyFirstActor>(AMyFirstActor::StaticClass(), actorSpawnLoacation);

}