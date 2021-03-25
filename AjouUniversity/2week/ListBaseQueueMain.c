#include <stdio.h>
#include<string.h>
#include "ListBaseQueue.h"
 
int main(void)
{
	int count = 0;//대기자 6명 제한을 위해서
	int num1,num2;
	
	// Queue의 생성 및 초기화 ///////
	Queue q;
	QueueInit(&q);
	
	while (1)
	{
		printf("1.관공서 도착\n2.관공서 퇴장\n3.서비스 종료\n");
		scanf_s("%d", &num1);
		if (num1 == 3) {
			printf("종료");
			return 0;
		}
		switch (num1)
		{
			case 1:
			{
				printf("1.대기자 등록\n2.취소\n");
				scanf_s("%d", &num2);
				if (num2 == 1) {
					
					if (++count >= 7) {
						count -= 1;
						printf("서비스를 제공할 수 없음\n\n");
						break;
					}
					getchar();
					Enqueue(&q);
					
					printf("\n");
					break;
					
				}
				else if (num2 == 2) {
					printf("\n");
					break;
				}
				else {
					printf("다시 입력하세요.\n\n");
					break;
				}
			}

			case 2:
			{
				
				Dequeue(&q);
				--count;
				
				printf("\n\n");
				
				break;
				
			}

			default:
				printf("다시 입력하세요. \n\n");
				break;
		}
			
	}
	
	return 0;
}
