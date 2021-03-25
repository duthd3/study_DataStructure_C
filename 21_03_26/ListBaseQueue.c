#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"
#include <string.h>

void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
	if (pq->front == NULL) {
		
			return TRUE;
	}
		
	else
		return FALSE;
}

void Enqueue(Queue * pq)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	printf("이름:");
	gets_s(newNode->Name,20);
	newNode->next = NULL;
	if(QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

int Dequeue(Queue * pq)
{
	
	Node * delNode;
	

	if (QIsEmpty(pq))
	{
		printf("대기중인 고객 없음.");
		return 1;
	}

	delNode = pq->front;
	
	pq->front = pq->front->next;
	printf("고객:%s", delNode->Name);
	free(delNode);
	return 1;
	
}
