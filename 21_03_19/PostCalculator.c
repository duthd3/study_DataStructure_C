#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) //후위표기법의 수식 계산 함수
{
	Stack stack;
	int expLen = strlen(exp);
	char tok, op1, op2;

	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok)) //tok이 정수라면
			{
				SPush(&stack, tok - '0'); //문자를 숫자로 변환해서 스택에 쌍는다.
			}
		else
		{
			op2 = SPop(&stack);
			op1 = SPop(&stack);
			switch (tok)
			{
			case '+':
				SPush(&stack, op1 + op2);
				break;

			case '-':
				SPush(&stack, op1 - op2);
				break;
			case '*':
				SPush(&stack, op1 * op2);
				break;
			case '/':
				SPush(&stack, op1 / op2);
				break;
			}
		}


	}
	return SPop(&stack);

}
