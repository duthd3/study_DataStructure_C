#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;
typedef void VisitFuncPtr(BTData data);
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;

/*** BTreeNode 관련 연산들 ****/
BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
#endif