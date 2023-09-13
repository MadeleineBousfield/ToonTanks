// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	
public:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();
	;
	APlayerController* GetTankPlayerController() const { return TankPlayerController; }

private:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* Camera;

//movement & inputs
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MoveSpeed = 200.f;

	UPROPERTY(EditAnywhere, Category = "Movement") 
		float TurnRate = 45.f;
	
	void Move(float value);
	void Turn(float value);

	APlayerController* TankPlayerController;
	
};
