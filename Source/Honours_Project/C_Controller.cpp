// Fill out your copyright notice in the Description page of Project Settings.


#include "C_Controller.h"

// Sets default values
AC_Controller::AC_Controller()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_Controller::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AC_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AC_Controller::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveX", this, &AC_Controller::Vertical_Movement);
	InputComponent = > BindAxis("MoveY", this, &AC_Controller::Horizontal_Movement);

	InputComponent = > BindAxis("CameraSide", this, &AC_Controller::AddControllerYawInput);
	InputComponent->BindAxis("CameraUp", this, &AC_Controller::AddControllerPitchInput);

	InputComponent = > BindAction("Interaction", IE_Pressed, this, &AC_Controller::Collect);
    InputComponent->BindAction("Ray", IE_Pressed, this, &AC_Controller::RayCast);
	InputComponent->BindAction("InventoryPlus", IE_Pressed, this, &AC_Controller::InventoryPlus);
	InputComponent->BindAction("InventoryMinus", IE_Pressed, this, &AC_Controller::InventoryMinus);

}



