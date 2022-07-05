// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectADefaultItem.h"

// Sets default values
AProjectADefaultItem::AProjectADefaultItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AProjectADefaultItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectADefaultItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectADefaultItem::ItemInteraction()
{
	PrimaryActorTick.bCanEverTick = true;
}
