// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS() //언리얼 클래스임을 나타내는 것
class TESTUNREALENGINE_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere) //언리얼 프로퍼티임을 나타내는 것
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Hp;
	
	UPROPERTY(EditAnywhere, Category = BattleStat)
	int32 Mp;
};
