// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <fstream>
#include <iostream>
#include "SimpleExcelOperations.generated.h"

UCLASS()
class SIMPLEEXCELPLUGIN_API ASimpleExcelOperations : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleExcelOperations();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Excel")
		void WriteDataToCell(FString Data);

	UFUNCTION(BlueprintCallable, Category = "Excel")
		bool OpenFile(FString filename, bool Rewrite);

	UFUNCTION(BlueprintCallable, Category = "Excel")
		void CloseFile();

	std::ofstream outputfile;
	std::string filename;
	std::string data;

};
