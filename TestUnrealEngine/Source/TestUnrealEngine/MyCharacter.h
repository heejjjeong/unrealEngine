// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TESTUNREALENGINE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();
	void AttackCheck();

	void UpDown(float value);
	void LeftRight(float value);
	void Yaw(float value);

	UFUNCTION()
	//������ �� ���� ���ڸ� �޴� �Լ��� ����� ��� ��
	void OnAttackMontageEnded(UAnimMontage* AM, bool bInterrupted);

public:
	const float GetUpDownValue() const { return UpDownValue; }
	const float GetLeftRightValue() const { return LeftRightValue; }

	
private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent*	SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent*		Camera;

	UPROPERTY(VisibleAnywhere, Category=Pawn)
	bool isAttack = false;

	UPROPERTY()
	class UMyAnimInstance* AnimInstance;

	UPROPERTY()
	//���� ���° ������ �ϰ� �ִ���
	int32 AttackIndex = 0;

	UPROPERTY()
	float UpDownValue = 0.f;
	
	UPROPERTY()
	float LeftRightValue = 0.f;

};
