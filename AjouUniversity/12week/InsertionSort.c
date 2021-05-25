#include<stdio.h>

void ISort(int arr[], int n)
{
	int i, j;
	int data;

	for (i = 1; i < n; i++)
	{
		data = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > data)
				arr[j + 1] = arr[j];
			else
				break;
		}
		arr[j + 1] = data;
	}
}

int main(void)
{
	int arr[15] = { 1,300,200,104,101,91,88,60,15,31,12,26,82,51,6 };	
	int i,j;

	printf("정렬할 데이터: ");
	for (i = 0; i < 15; i++)
		printf("%d ", arr[i]);
	ISort(arr, 15);
	printf("\n");
	printf("Insertion Sort: ");
	for (j = 0; j < 15; j++)
	{
		printf("%d ", arr[j]);
	}

	return 0;
}
