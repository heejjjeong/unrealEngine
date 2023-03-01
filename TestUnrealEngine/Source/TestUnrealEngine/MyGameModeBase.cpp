// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"

AMyGameModeBase::AMyGameModeBase()
{
	//cpp클래스 
	DefaultPawnClass = AMyCharacter::StaticClass();
	
	////Blueprints 클래스
	///*규칙 : 그냥 경로 가져오면 Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter'
	//인데 블루프린트는 뒤에 _C를 붙여줘야함  */ 
	//static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(
	//	TEXT("Blueprint'/Game/Blueprints/BP_MyCharacter.BP_MyCharacter_C'"));

	//if (BP_Char.Succeeded())
	//{
	//	DefaultPawnClass = BP_Char.Class;
	//}
} 