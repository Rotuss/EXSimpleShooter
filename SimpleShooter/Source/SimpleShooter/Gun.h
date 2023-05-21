// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PullTrigger();

	UFUNCTION(BlueprintPure)
	int32 GetAmmoMaxCount() const;
	
	UFUNCTION(BlueprintPure)
	int32 GetAmmoCount() const;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;
	
	UPROPERTY(EditAnywhere)
	USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;

	AController* GetOwnerController() const;
	
	bool GunTrace(FHitResult& Hit, FVector& ShotDirection);

	UPROPERTY(EditAnywhere)
	float MaxRange = 1000;

	UPROPERTY(EditAnywhere)
	float Damage = 10;

	UPROPERTY(EditAnywhere)
	float ReloadDelay = 3.0f;
	
	UPROPERTY(EditAnywhere)
	int32 AmmoMaxCount = 50;

	UPROPERTY(EditAnywhere)
	int32 AmmoCount;

	FTimerHandle ReloadTimer;

	bool IsReloading = false;

};
