#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee* WhosNightDuty(List* plist, char* name, int day);
void ShowEmployeeInfo(Employee* emp);
int main(void)
{
	int i;
	Employee* pemp;

	//List의 생성 및 초기화
	List list;
	ListInit(&list);

	//4명의 데이터 저장
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1111;
	strcpy_s(pemp->name, sizeof(pemp->name), "Terry");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2222;
	strcpy_s(pemp->name, sizeof(pemp->name), "Anna");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3333;
	strcpy_s(pemp->name, sizeof(pemp->name), "Song");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4444;
	strcpy_s(pemp->name, sizeof(pemp->name), "Kim");
	LInsert(&list, pemp);

	//Terry뒤로 3일뒤 당직자는?
	pemp = WhosNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);

	//Kim뒤로 15일뒤 당직자는?
	pemp = WhosNightDuty(&list, "Kim", 15);
	ShowEmployeeInfo(pemp);
	//할당된 메모리의 전체소멸
	if (LFirst(&list, &pemp))
	{
		free(pemp);

		for (i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &pemp))
				free(pemp);
		}
	}
	return 0;
}

Employee* WhosNightDuty(List* plist, char* name, int day)
{
	int i, num;
	Employee* ret;

	num = LCount(plist);

	//이름 찾기
	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);
			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL; //해당하는 이름이 존재하지 않으면
	}

	//그 뒤로 며칠뒤
	for (i = 0; i < day; i++)
		LNext(plist, &ret);
	return ret;
}

void ShowEmployeeInfo(Employee* emp)
{
	printf("Employee name:%s \n", emp->name);
	printf("Employee number:%d \n", emp->empNum);
}
