#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	int i;
	int sum = 0;

	ListInit(&list);

	for (i = 1; i <= 9; i++)
	{
		LInsert(&list, i);
	}

	if(LFirst(&list, &data))
	{
		sum += data;

		while(LNext(&list, &data)) 
			sum += data;
		
	}

	printf("합계:%d \n", sum);

	if (LFirst(&list, &data)) //2의 배수와 3의 배수에 해당하는 값을 모두 삭제
	{
		if (data % 2 == 0 || data % 3 == 0)
		{
			LRemove(&list);
		}
		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
			{
				LRemove(&list);
			}
		}
	}
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);

	}

	return 0;
	


	
}
