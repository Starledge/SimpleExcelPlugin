// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleExcelOperations.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

// Sets default values
ASimpleExcelOperations::ASimpleExcelOperations()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASimpleExcelOperations::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASimpleExcelOperations::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASimpleExcelOperations::WriteDataToCell(FString Data)
{
    outputfile << TCHAR_TO_UTF8(*Data);
    outputfile << std::endl;
}

bool ASimpleExcelOperations::OpenFile(FString fileName, bool Rewrite)
{
    this->filename = TCHAR_TO_UTF8(*fileName);
    std::ios_base::openmode options = Rewrite ? (std::ofstream::out) : (std::ofstream::app);
    outputfile.open(this->filename, options);
    bool opened = outputfile.is_open();
    if (!outputfile.is_open())
    {
        UE_LOG(LogTemp, Warning, TEXT("File Not opened error"));
    }
    return opened;
}

void ASimpleExcelOperations::CloseFile()
{
    outputfile.close();
}

