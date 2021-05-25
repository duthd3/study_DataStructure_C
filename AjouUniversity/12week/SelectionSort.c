#include<stdio.h>

void SSort(int arr[], int n)
{
	int i, j;
	int min;
	int temp;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min])
				min = j;
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;

	}
}

int main(void)
{
	int arr[15] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };
	int i, j;
	printf("정렬할 데이터: ");
	for (i = 0; i < 15; i++) {
		printf("%d ", arr[i]);
	}
	SSort(arr, 15);
	printf("\n");
	printf("Selection Sort: ");
	for (j = 0; j < 15; j++) {
		printf("%d ", arr[j]);
	}

	return 0;
}
