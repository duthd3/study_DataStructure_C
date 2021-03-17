#include <stdio.h>
#include "ArrayBaseStack.h"

int main(void)
{
	// Stack의 생성 및 초기화 ///////
	Stack stack;
	Stack stack2;
	StackInit(&stack);
	StackInit(&stack2);

	// 데이터 넣기 ///////
	SPush(&stack, 1);  SPush(&stack, 2);
	SPush(&stack, 3);  SPush(&stack, 4);
	SPush(&stack, 5);

	SPush(&stack2, 11);  SPush(&stack2, 22);
	SPush(&stack2, 33);  SPush(&stack2, 44);
	SPush(&stack2, 55);

	// 데이터 꺼내기 ///////
	while (!SIsEmpty(&stack2))
		printf("%d ", SPop(&stack2));
	while(!SIsEmpty(&stack))
		printf("%d ", SPop(&stack)); 

	

	return 0;
}
