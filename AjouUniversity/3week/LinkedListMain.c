#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {
	int element;
	struct node *next;
	struct node *prev;
}NODE;

typedef struct list {
	NODE *head;
	NODE *tail;
}LIST;

int list_size;


/*메뉴 출력함수*/
int menu()
{
	int i;

	
	printf("1. 추 가 \n");
	printf("2. 삭 제\n");
	printf("3. 출 력\n");
	printf("4. 역 순 출 력\n");
	printf("5. 종 료\n");
	

	printf("선택: ");
	scanf_s("%d", &i);

	return i;
}

void display(LIST *pList)
{
	NODE *pNode;

	if (pList->head == NULL) { //리스트가 비어 있는 경우
		printf("\n 리스트가 비어 있습니다.\n\n");
	}
	else { //리스트에 데이터가 존재하는 경우
		printf("\n 리스트 : ");
		for (pNode = pList->head; pNode != NULL; pNode = pNode->next) { //리스트의 head에서부터 순차적으로 데이터 출력
			printf("%d ", pNode->element);
		}
		printf("\n\n");
	}
	
	
}

void reverse_display(LIST *pList)
{
	NODE *pNode;

	if (pList->head == NULL) {//리스트가 비어 있는 경우
		printf("\n 리스트가 비어 있습니다.\n\n");
	}
	else {//리스트에 데이터가 존재하는 경우
		printf("\n 리스트 : ");
		for (pNode = pList->tail; pNode != NULL; pNode = pNode->prev) //리스트의 tail에서부터 역순으로 데이터 출력
		{
			printf("%d ", pNode->element);
		}
		printf("\n\n");
	}
}

/*노드 생성 함수*/
NODE * make_node(int elem)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE)); 
	newNode->element = elem;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

/*리스트 초기화 함수*/
void init(LIST *pList)
{
	list_size = 0;

	pList->head = NULL;
	pList->tail = NULL;
}

/* linked list 에서 pos위치에 elme을 가진 노드를 추가하는 코드 작성 */
void insert_elem(LIST *pList, int pos, int elem)
{
	int i;
	NODE *pNode;
	NODE *newNode = make_node(elem); // 노드 생성

	if (pList->head == NULL) // 빈 리스트에 추가하는 경우
	{
		pList->head = newNode;
		pList->tail = newNode;
		list_size++;
	}
	else {		
		if (pos == 0) { // 리스트 첫번째 위치에 추가하는 경우
			newNode->next = pList->head;
			pList->head->prev = newNode;
			pList->head = newNode;
			list_size++;
		}
		else if (pos == list_size) { // 리스트 마지막 위치에 추가하는 경우
			newNode->prev = pList->tail;
			pList->tail->next = newNode;
			pList->tail = newNode;
			list_size++;
		}
		else { // 중간 위치에 추가하는 경우
			for (i = 0, pNode = pList->head; pNode != NULL; pNode = pNode->next) {
				if (i == pos - 1) {
					pNode->next->prev = newNode;
					newNode->next = pNode->next;
					pNode->next = newNode;
					newNode->prev = pNode;
					list_size++;
				}
				i++;
			}
		}
	}
			
	
}
/*linked list 에서 pos위치의 노드를 삭제하는 코드 작성*/
void remove_pos(LIST *pList, int pos)
{
	int i;
	NODE *pNode;
	NODE *rNode;

	if (pos == 0) { //리스트 첫번째 위치의 노드를 삭제하는 경우
		if (list_size == 1) {
			rNode = pList->head;
			pList->head = NULL;
			pList->tail = NULL;
		}
		else {
			rNode = pList->head;
			pList->head = pList->head->next;
			pList->head->prev = NULL;
		}
		
		free(rNode);
		list_size--;
	}
	else if (pos == list_size - 1) { // 리스트 마지막 노드를 삭제하는 경우
		rNode = pList->tail;
		pList->tail = pList->tail->prev;
		pList->tail->next = NULL;
		free(rNode);
		list_size--;
	}
	else { // 중간 노드를 삭제하는 경우
		for (i = 0, pNode = pList->head; pNode != NULL; pNode = pNode->next)
		{
			if (i == pos) {
				pNode->prev->next = pNode->next;
				pNode->next->prev = pNode->prev;
				free(pNode);
				list_size--;
				break;
			}
			i++;
		}
	}
}

/*
linked list 에서 element를 찾고 위치를 출력하는 코드 작성

*/
int search_elem_pos(LIST *pList, int elem)
{
	int i;	
	NODE *pNode;
		
	for (i = 0, pNode = pList->head; pNode != NULL; pNode = pNode->next)
	{
		if (pNode->element == elem) {				
			return i;
		}
		i++;
	}
	
	return -1;
}

/*데이터가 추가될 위치를 검색하는 함수 */
int search_input_pos(LIST *pList, int elem)
{
	int i;
	NODE *pNode;
	
	for (i = 0, pNode = pList->head; pNode != NULL; pNode = pNode->next)
	{
		if (pNode->element <= elem) {
			return i;
		}
		i++;
	}
	
	return i;
}

int main() 
{
	int data;
	int pos;
	
	LIST list;

	init(&list); // 리스트 초기화
	

	while (1) {
		switch (menu()) { //메뉴 선택
		case 1: // 추가 메뉴 선택시
			printf("입력 : ");
			scanf_s("%d", &data);
			if (search_elem_pos(&list, data) == -1) { // 중복 데이터가 있는지 검색
				pos = search_input_pos(&list, data);  //추가할 데이터 삽입될 위치 찾기
				insert_elem(&list, pos, data);		 // pos위치에 데이터 삽입
				printf("성공했습니다.\n\n");
			}	
			else { // 중복 데이터가 존재하는 경우
				printf("중복된 데이터 입니다.\n\n");
			}
			break;
		case 2:
			if (list.head == NULL) { //리스트가 비어 있는 경우
				printf("리스트가 비어 있습니다.\n\n");
				continue;
			}

			printf("입력 : ");
			scanf_s("%d", &data);
			if ((pos = search_elem_pos(&list, data)) != -1) { // 삭제할 데이터 검색
				remove_pos(&list, pos); // 데이터 삭제
				printf("성공 했습니다.\n\n");
			}
			else { // 리스트에 삭제할 데이터가 없는 경우
				printf("찾는 값이 없습니다.\n\n");
			}
			break;
		case 3:
			display(&list); // 리스트 출력
			break;
		case 4:
			reverse_display(&list); //리스트 역순으로 출력
			break;
		case 5:			
			exit(1); // 종료
			return 0;
		default:
			break;

		}
		
	}

//end
	return 0;
}
