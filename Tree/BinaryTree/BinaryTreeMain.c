#include <stdio.h>
#include "BinaryTree.h"

void ShowIntData(int data);

void ShowIntData(int data)
{
	printf("%d \n", data*10);
}

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);

	MakeLeftSubTree(bt4, bt3);
	MakeRightSubTree(bt4, bt2);
	MakeLeftSubTree(bt3, bt1);

	InorderTraverse(bt4, ShowIntData);
	return 0;
}
