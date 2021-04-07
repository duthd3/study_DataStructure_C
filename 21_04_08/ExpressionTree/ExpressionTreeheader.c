#ifndef __EXPRESSION_TREE_H
#define __EXPRESSION_TREE_H

#include "BinaryTree2.h"

BTreeNode* MakeExpTree(char exp[]);//수식트리구성
int EvaluateExpTree(BTreeNode* bt);//수식트리계산

void ShowPrefixTypeExp(BTreeNode* bt);//전위 표기법 기반 출력
void ShowInfixTypeExp(BTreeNode* bt);//중위 표기법 기반 출력
void ShowPostfixTypeExp(BTreeNode* bt);//후위 표기법 기반 출력

#endif
