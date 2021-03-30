#include<stdio.h>
#include "BinaryTree.h"

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode(); //노드bt1생성
	BTreeNode* bt2 = MakeBTreeNode(); //노드bt2생성
	BTreeNode* bt3 = MakeBTreeNode(); //노드bt3생성
	BTreeNode* bt4 = MakeBTreeNode(); //노드bt4생성
	BTreeNode* bt5 = MakeBTreeNode();
	BTreeNode* bt6 = MakeBTreeNode();
	BTreeNode* bt7 = MakeBTreeNode();
	BTreeNode* bt8 = MakeBTreeNode();
	BTreeNode* bt9 = MakeBTreeNode();
	BTreeNode* bt10 = MakeBTreeNode();
	BTreeNode* bt11 = MakeBTreeNode();


	SetData(bt1, 6); //bt1에 1저장
	SetData(bt2, 4); //bt2에 2저장
	SetData(bt3, 9); //bt3에 3저장
	SetData(bt4, 2); //bt4에 4저장
	SetData(bt5, 5); 
	SetData(bt6, 7);
	SetData(bt7, 10);
	SetData(bt8, 1);
	SetData(bt9, 3);
	SetData(bt10, 8);
	SetData(bt11, 11);
	
	//bt1의 자식노드
	MakeLeftSubTree(bt1, bt2); //bt2를 bt1의 왼쪽 자식 노드로 만든다.
	MakeRightSubTree(bt1, bt3);//bt3을 bt1의 오른쪽 자식 노드로 만든다.
	//bt2의 자식노드
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	//bt3의 자식노드
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);
	//bt4의 자식노드
	MakeLeftSubTree(bt4, bt8);
	MakeRightSubTree(bt4, bt9);
	//bt7의 자식노드
	MakeLeftSubTree(bt7, bt10);
	MakeRightSubTree(bt7, bt11);
	
	
	


	printf("Inorder traversal의 결과:\n");
	InorderTraverse(bt1);
	printf("Preorder traversal의 결과: \n");
	PreorderTraverse(bt1);
	printf("Postorder traversal의 결과:\n");
	PostorderTraverse(bt1);
	/*
	//bt1의 왼쪽 자식 노드의 데이터 출력
	printf("%d \n", GetData(GetLeftSubTree(bt1)));
	
	//bt1의 왼쪽 자식노드의 왼쪽 자식 노드의 데이터 출력
	printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	*/

	return 0;


}
