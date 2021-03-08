#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "NameCard.h"


NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(newCard->name, 3, name);
	strcpy_s(newCard->phone,13, phone);
	return newCard;
}

void ShowNameCardInfo(NameCard* pcard) //NameCard 구조체 변수의 정보 출력
{
	printf("[이름]:%s \n", pcard->name);
	printf("[번호]:%s \n", pcard->phone);

}


int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);

}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strcpy_s(pcard->phone, 13, phone);
}
