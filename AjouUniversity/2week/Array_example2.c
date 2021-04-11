#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#define MAX_SIZE 101

int main(void)
{
	int i, n, list[MAX_SIZE];

	printf("Enter the number of number to generate: ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		list[i] = rand() % 1000;
		printf("%d\n", list[i]);
	}
}
