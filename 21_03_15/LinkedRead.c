#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
}Node;

int main(void)
{
	Node* head = NULL; //연결리스트의 머리 부분
	Node* tail = NULL; //꼬리부분
	Node* cur = NULL; //현재위치 

	Node* newNode = NULL; //새로운 노드
	int readData;

	//데이터입력
	while (1)
	{
		printf("자연수 입력:");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData; //새로운 노드에 데이터 저장
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;// 헤드가 새로운 노드를 가리킨다.
		else
			tail->next = newNode; //다음노드와의 연결
		tail = newNode;

	}
	printf("\n");

	//입력 받은 데이터의 전체출력
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL)
		printf("저장된 자연수가 존재하지 않습니다. \n");
	else
	{
		cur = head;
		printf("%d ", cur->data); //cur(현재위치)의 데이터 출력

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
			
		}
	}
	printf("\n\n");
	//메모리의 해체과정
	if (head == NULL)
		return 0; //해체할 노드가 존재하지 않는다.
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d를 삭제합니다.\n", head->data);
		free(delNode);//첫번째 노드 삭제

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d를 삭제합니다.\n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}
