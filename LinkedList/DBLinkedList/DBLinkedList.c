#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	plist->head->prev = NULL;
	plist->tail->next = NULL;
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;
	plist->numOfData = 0;

}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->tail;
	
	plist->tail->prev->next = newNode;
	newNode->prev = plist->tail->prev;
	plist->tail->prev = newNode;
	

	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->head == NULL)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List * plist, Data * pdata)
{
	if(plist->cur->prev == plist->head)
		return FALSE;
	
	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	
	return TRUE;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

Data Remove(List* plist)
{
	Node* rpos = plist->cur;
	Data rem = plist->cur->data;

	plist->cur->next->prev = plist->cur->prev;
	plist->cur->prev->next = plist->cur->next;
	plist->cur = plist->cur->prev;

	free(rpos);
	(plist->numOfData)--;
	return rem;
}
