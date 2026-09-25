// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/PickupActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
APickupActor::APickupActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	bReplicates = true;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &APickupActor::OnOverlapBegin);
	}
}

void APickupActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Registrar la variable bIsAvailable para su replicación
	DOREPLIFETIME(APickupActor, bIsAvailable);
}

void APickupActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
								  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
								  bool bFromSweep, const FHitResult& SweepResult)
{
	// 1. Verificación de Autoridad (Servidor) y disponibilidad
	if (!HasAuthority() || !bIsAvailable)
	{
		return;
	}

	// 2. Comprobar que sea un Actor válido que no sea él mismo
	if (OtherActor && OtherActor != this)
	{
		// 3. Modificar el estado en el SERVIDO
		bIsAvailable = false;

		// 4. El servidor aplica el cambio visual en su propia instancia
		UpdateVisualState();
	}
}

void APickupActor::OnRep_bIsAvailable()
{
	// Se ejecuta AUTOMÁTICAMENTE en todos los CLIENTES cuando reciben la actualización
	UpdateVisualState();
}

void APickupActor::UpdateVisualState()
{
	if (!bIsAvailable)
	{
		// Oculta el Actor y deshabilita su colisión para que no vuelva a consumirse
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
	}
}

