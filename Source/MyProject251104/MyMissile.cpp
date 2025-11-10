// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMissile.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AMyMissile::AMyMissile()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(30.0f, 8.0f, 8.0f));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Missile(TEXT("/Script/Engine.StaticMesh'/Game/Data/SM_Rocket.SM_Rocket'"));

	if (SM_Missile.Succeeded())
	{
		Body->SetStaticMesh(SM_Missile.Object);
	}
	Body->SetRelativeRotation(FRotator(270.0f, 0.0f, 0.0f));
	
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	Projectile->ProjectileGravityScale = 0.0f;
	Projectile->MaxSpeed = 2000.0f;
	Projectile->InitialSpeed = 2000.0f;
}

// Called when the game starts or when spawned
void AMyMissile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector());
}

// Called to bind functionality to input
void AMyMissile::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}