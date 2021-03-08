#include<stdio.h>
#include<stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"
#define _CRT_SECURE_NO_WARNINGS
int main(void)
{
	List list;
	NameCard* pcard;
	ListInit(&list);

	pcard = MakeNameCard("이진수", "010-1111-2222");
	LInsert(&list, pcard); //pcard >> 주소값 반환
	
	pcard = MakeNameCard("한지영", "010-2222-5555");
	LInsert(&list, pcard);

	pcard = MakeNameCard("조수진", "010-3333-7777");
	LInsert(&list, pcard);

	//한지영의 정보를 조회하여 출력
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "한지영"))
			ShowNameCardInfo(pcard);

		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "한지영"))
					ShowNameCardInfo(pcard);
			}
		}
	}
	//조수진의 정보를 조회하여 전화번호 변경
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "조수진"))
			ChangePhoneNum(pcard, "010-1234-5678");

		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "조수진"))
					ChangePhoneNum(pcard, "010-1234-5678");
			}
		}
	}
	//이진수의 정보를 조회하여 정보 삭제
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "이진수")) {
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "이진수")) {
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}
	if (LFirst(&list, &pcard))
	{
		
			ShowNameCardInfo(pcard);

		
	
			while (LNext(&list, &pcard))
			{				
				ShowNameCardInfo(pcard);
			}
		
	}
	return 0;

}
