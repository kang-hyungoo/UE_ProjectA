// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Engine/DataTable.h"
#include "ProjectADefinedStruct.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API UProjectADefinedStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
};


USTRUCT(BlueprintType)
struct  FCharacterDataStruct :public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkeletalMesh* SK_Mesh_Body;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class TSubclassOf<UAnimInstance> Animation;
};