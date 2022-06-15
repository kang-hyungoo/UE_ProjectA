// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectADoor.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AProjectADoor::AProjectADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	DefaultSceneRoot->SetupAttachment(RootComponent);

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	Scene->SetupAttachment(DefaultSceneRoot);

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(Scene);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube"));

	if (CubeMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(CubeMeshAsset.Object);
		DoorMesh->SetRelativeLocation(FVector(-100.0f, 0.0f, 100.0f));
		DoorMesh->SetRelativeScale3D(FVector(2.0f, 0.1f, 2.0f));
	}

	//StaticMesh'/Engine/BasicShapes/Cube.Cube'

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(DefaultSceneRoot);
	CollisionBox->SetRelativeLocation(FVector(-100.0f, 0.0f, 120.0f));
	CollisionBox->SetRelativeScale3D(FVector(4.0f, 3.0f, 4.0f));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AProjectADoor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AProjectADoor::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AProjectADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AProjectADoor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (UGameplayStatics::GetPlayerPawn(GetWorld(), 0) == OtherActor)
		{
			Scene->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
		}
	}
}

void AProjectADoor::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		if (UGameplayStatics::GetPlayerPawn(GetWorld(), 0) == OtherActor)
		{
			Scene->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
}
