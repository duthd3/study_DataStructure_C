#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data; //데이터를 담을 공간
	struct _node* next; //데이터 연결의 도구!
} Node;

int main(void)
{
	Node* head = NULL;    // NULL 포인터 초기화(리스트의 머리를 가리키는 포인터변수)
	Node* tail = NULL; //리스트의 꼬리를 가리키는 포인터변수
	Node* cur = NULL; //저장된 데이터의 조회에 사용되는 포인터 변수

	Node* newNode = NULL;
	int readData;

	/**** 데이터를 입력 받는 과정 ****/
	while (1)
	{
		printf("자연수 입력: ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		/*** 노드의 추가과정 ***/
		newNode = (Node*)malloc(sizeof(Node)); 
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
		{

			head = newNode;
			tail = newNode;
		}	
		else
			newNode->next = head; //노드가 머리에 추가되게 한다.

		head = newNode;
	}
	printf("\n");

	/**** 입력 받은 데이터의 출력과정 ****/
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else
	{
		cur = head;
		printf("%d  ", cur->data);   // 첫 번째 데이터 출력

		while (cur->next != NULL)    // 두 번째 이후의 데이터 출력
		{
			cur = cur->next; //cur이 다음 노드를 가리키게 한다.
			printf("%d  ", cur->data); //cur이 가리키는 노드를 출력한다.
		}
	}
	printf("\n\n");

    /**** 메모리의 해제과정 ****/

/*	if (head == NULL)
	{
		return 0;    // 해제할 노드가 존재하지 않는다.
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);    // 첫 번째 노드의 삭제

		while (delNextNode != NULL)    // 두 번째 이후의 노드 삭제 위한 반복문
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);    // 두 번째 이후의 노드 삭제
		}
	}*/
	

	return 0;
}
