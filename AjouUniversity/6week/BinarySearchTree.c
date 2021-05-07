#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>


struct node
{
	char name[10];
	int day;
	char area[20];
	struct node* left, * right;
};

// 새로운 노드(참가자) 생성
struct node* newNode(char name[], int day, char area[])
{
	struct node* temp = (struct node*)malloc(sizeof(struct node)); // 메모리 할당

	
	strcpy(temp->name, name);
	temp->day = day;
	strcpy(temp->area, area);

	
	temp->left = temp->right = NULL;

	return temp;
}

// BST에 참가자 추가
struct node* insert(struct node* node, char name[], int day, char area[])
{
	// 트리가 비어 있으면 노드 생성
	if (node == NULL)
		return newNode(name, day, area);

	
	if (strcmp(name, node->name) < 0) 
	{
		node->left = insert(node->left, name, day, area);
	}
	else if (strcmp(name, node->name) > 0)
	{
		node->right = insert(node->right, name, day, area);
	}
	else
	{
		printf("이미 등록된 참가자입니다.\n");
	}

	return node;
}

struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	
	while (current->left != NULL)
		current = current->left;

	return current;
}

// BST에서 노드 삭제
struct node* deleteNode(struct node* root, char name[])
{
	//BST가 비어있으면 종료
	if (root == NULL)
	{
		printf("참가자가 없습니다.\n");
		return root;
	}

	if (strcmp(name, root->name) < 0) // 현재 노드보다 작으면 왼쪽으로 이동
	{
		root->left = deleteNode(root->left, name);
	}
	else if (strcmp(name, root->name) > 0) // 현재 노드보다 크면 오른쪽으로 이동
	{
		root->right = deleteNode(root->right, name);
	}
	else // 같으면 삭제
	{
	
		printf("참가가 취소되었습니다.\n");

		if (root->left == NULL)
		{
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		
		struct node* temp = minValueNode(root->right);
		strcpy(root->name, temp->name);
		root->right = deleteNode(root->right, temp->name);


	}
	return root;
}


struct node* searchNode(struct node* root, char name[])
{
	// base case 
	if (root == NULL)
	{
		printf("참가자가 없습니다.\n");
		return root;
	}

	if (strcmp(name, root->name) < 0)// 현재 노드보다 작으면 왼쪽으로 이동
	{
		root->left = searchNode(root->left, name);

	}
	else if (strcmp(name, root->name) > 0)// 현재 노드보다 크면 오른쪽으로 이동
	{
		root->right = searchNode(root->right, name);
	}
	else if (strcmp(name, root->name) == 0)// 같으면 데이터 출력
	{
		printf("검색이 완료되었습니다.\n");
		printf("%s\n", root->name);
		printf("%d\n", root->day);
		printf("%s\n", root->area);
	}



	return root;
}

struct node* changeNode(struct node* root, char name[], char temp[])
{
	 
	if (root == NULL)
	{
		printf("참가자가 없습니다.\n");
		return root;
	}

	if (strcmp(name, root->name) < 0)// 현재 노드보다 작으면 왼쪽으로 이동
	{
		root->left = changeNode(root->left, name, temp);
	}
	else if (strcmp(name, root->name) > 0)// 현재 노드보다 크면 오른쪽으로 이동
	{
		root->right = changeNode(root->right, name, temp);
	}
	else // 같으면 정보 수정
	{
		if (isdigit(temp[0]) != 0) 
		{
			root->day = atoi(temp);
		}
		else // 숫자가 아니면
		{
			strcpy(root->area, temp); 
		}
		printf("변경이 완료되었습니다.\n");
		printf("%s\n", root->name);
		printf("%d\n", root->day);
		printf("%s\n", root->area);
	}
	return root;
}

// 메뉴 출력 및 선택
int menu()
{
	int sel;
	printf("입력(1), 검색(2), 정보변경(3), 참가취소(4), 종료(5)\n");

	scanf("%d", &sel);

	return sel;
}


int main()
{
	struct node* root = NULL;
	char name[10];
	int day;
	char area[20];
	char temp[20];

	printf("참가자 정보 관리 프로그램\n\n");

	while (1) {
		switch (menu()) { // 메뉴 화면 출력 및 선택
		case 1:
			printf("정보를 입력하십시오\n이름(영문 10자이내)\n");
			scanf("%s", name);
			printf("신청날짜(YYYYMMDD)\n");
			scanf("%d", &day);
			printf("신청지역(영문 20자이내)\n");
			scanf("%s", area);
			root = insert(root, name, day, area);//이름, 신청일, 신청지역을 root에 삽입			
			break;
		case 2:
			printf("검색할 이름을 입력하십시오\n");
			scanf("%s", name);
			searchNode(root, name); // 이진탐색트리에서 이름 검색
			break;
		case 3:
			printf("변경할 정보를 입력하십시오(이름, 정보)\n");
			scanf("%s %s", name, temp);
			changeNode(root, name, temp); // 이진탐색트리에서 이름으로 검색하여 정보 변경
			break;
		case 4:
			printf("취소할 이름을 입력하십시오(이름, 정보)\n");
			scanf("%s", name);
			deleteNode(root, name);	 // 이진탐색트리에서 이름으로 검색하여 정보 삭제

			break;
		case 5:
			printf("종료합니다.\n");
			exit(1);
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}
	}
	return 0;
}
