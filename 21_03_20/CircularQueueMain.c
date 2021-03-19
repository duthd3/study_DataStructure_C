#include<stdio.h>
#include "CircularQueue.h"

int main(void)
{
	//Queue의 생성 및 초기화
	Queue q;
	QueueInit(&q);

	//데이터 넣기
	Enqueue(&q, 1); Enqueue(&q, 2);
	Enqueue(&q, 3); Enqueue(&q, 4);
	Enqueue(&q, 5);


	
	//데이터 꺼내기
	
		printf("%d ", Dequeue(&q));
		printf("%d ", Dequeue(&q));
		printf("%d \n", QPeek(&q));
		printf("%d ", Dequeue(&q));
		printf("%d \n", QPeek(&q));
		printf("%d ", Dequeue(&q));
		printf("%d ", Dequeue(&q));
		printf("%d \n", QPeek(&q));
	return 0;
}
