// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupActor.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class MULTIJUGADOR_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// Componentes del Pickup
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UBoxComponent> CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

	// Variable replicada. OnRep_bIsAvailable se ejecuta en clientes al cambiar
	UPROPERTY(ReplicatedUsing = OnRep_bIsAvailable, BlueprintReadOnly, Category = "Pickup")
	bool bIsAvailable = true;

	// Notificador de Replicación (RepNotify)
	UFUNCTION()
	void OnRep_bIsAvailable();

	// Evento de Superposición (Overlap)
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	// Función auxiliar para actualizar la representación visual y física
	void UpdateVisualState();

};
