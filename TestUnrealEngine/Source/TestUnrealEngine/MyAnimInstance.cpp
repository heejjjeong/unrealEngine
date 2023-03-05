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
	Montage_JumpToSection(Name, AttackMontage); //�ش� ��Ÿ���̸��� ��Ÿ�ָ� �־ ���� �ѱ�
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	//���⿡ ��.. �ش� Ÿ�ֿ̹� �Ҹ��� �ִ´ٴ��� �ϴ� ��Ÿ �۾��� �ϸ� ��
	//UE_LOG(LogTemp, Log, TEXT("AnimNotify_AttackHit"));
	
	OnAttackHit.Broadcast();
}
