// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "GameFrameWork/Character.h"
#include "GameFrameWork/PawnMovementComponent.h"
#include "MyCharacter.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Animations/Greystone_Skeleton_Montage.Greystone_Skeleton_Montage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		Speed = Pawn->GetVelocity().Size();

		auto Character = Cast<AMyCharacter>(Pawn);
		if (Character)
		{
			isFalling = Character->GetMovementComponent()->IsFalling();

			Vertical = Character->GetUpDownValue();
			Horizontal = Character->GetLeftRightValue();
		}
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	Montage_Play(AttackMontage, 1.f);
}

FName UMyAnimInstance::GetAttackMontageName(int32 SectionIndex)
{
	return FName(*FString::Printf(TEXT("Attack%d"), SectionIndex));
}

void UMyAnimInstance::JumpToSection(int32 SectionIndex)
{
	FName Name = GetAttackMontageName(SectionIndex);
	Montage_JumpToSection(Name, AttackMontage); //해당 몽타주이름과 몽타주를 넣어서 섹션 넘김
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	//여기에 뭐.. 해당 타이밍에 소리를 넣는다던지 하는 기타 작업을 하면 됨
	//UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));
	
	OnAttackHit.Broadcast();
}
