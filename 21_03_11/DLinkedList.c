#include<stdio.h>
#include<stdlib.h>
#include "DLinkedList.h"

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node)); //더미노드 생성
	plist->head->next = NULL; //더미노드 초기화
	plist->comp = NULL; //정렬의 기준
	plist->numOfData = 0; //데이터의수 0개 (더미노드는 포함x)
}

void FInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //노드 생성
	newNode->data = data; //노드에 데이터 저장

	newNode->next = plist->head->next; //NULL
	plist->head->next = newNode; //더미노드가 새로운 노드를 가리키게 된다.

	(plist->numOfData)++; //데이터의수 1개+
}
void SInsert(List* plist, LData data)
{
	//
}

void LInsert(List* plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur-> data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}
