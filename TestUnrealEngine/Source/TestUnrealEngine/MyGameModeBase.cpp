// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	//cppŬ���� 
	DefaultPawnClass = AMyCharacter::StaticClass();
	
	////Blueprints Ŭ����
	///*��Ģ : �׳� ��� �������� Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter'
	//�ε� �������Ʈ�� �ڿ� _C�� �ٿ������  */ 
	//static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(
	//	TEXT("Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter_C'"));

	//if (BP_Char.Succeeded())
	//{
	//	DefaultPawnClass = BP_Char.Class;
	//}
} 