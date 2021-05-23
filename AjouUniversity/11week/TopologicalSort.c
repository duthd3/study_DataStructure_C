#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000 

typedef struct node link;
struct node {
	int vertex; 
	link* next;  
};
typedef struct {
	int number;  
	link* linked;  
}nodes;


int topSort(nodes* arr[SIZE], int* result, int count)
{

	int q[SIZE];
	int a, b, i;
	a = 0, b = 0;
	while (1)
	{
		for (i = 0; i < SIZE; i++)
			if (arr[i] != NULL && arr[i]->number == 0)
			{
				q[a++] = i;
				result[b++] = i;
				arr[i]->number--;
			}


		if (a == 0)
		{
			if (a == count)
				return 0;
			else return 1;
		}

		for (int i = 0; i < a; i++)
		{
			link* p = arr[q[i]]->linked;
			while (p != NULL)
			{
				arr[p->vertex]->number--;
				p = p->next;
			}
		}
		a = 0;
	}
}


void adlist(nodes* arr[SIZE], int index, int x)
{
	nodes* temp = NULL;
	link* temp2 = NULL;
	if (arr[index] == NULL)
	{
		if ((temp = (nodes*)malloc(sizeof(nodes))) == NULL)
			exit(1);
		temp->number = 0;
		temp->linked = NULL;
		arr[index] = temp;
	}
	if (arr[x] == NULL)
	{
		if ((temp = (nodes*)malloc(sizeof(nodes))) == NULL)
			exit(2);
		temp->number = 0;
		temp->linked = NULL;
		arr[x] = temp;
	}
	arr[x]->number++;
	
	if ((temp2 = (link*)malloc(sizeof(link))) == NULL)
		exit(1);
	temp2->vertex = x;
	temp2->next = NULL;

	if (arr[index]->linked == NULL)
		arr[index]->linked = temp2;
	else
	{
		link* p = arr[index]->linked;
		while (p->next != NULL)
			p = p->next;
		p->next = temp2;
	}
}


int main()
{
	int i;
	nodes* arr[SIZE] = { NULL };  
	int result[SIZE];
	adlist(arr, 0, 1);
	adlist(arr, 1, 2);
	adlist(arr, 1, 3);
	adlist(arr, 1, 4);
	adlist(arr, 2, 7);
	adlist(arr, 3, 6);
	adlist(arr, 4, 5);
	adlist(arr, 4, 6);
	adlist(arr, 5, 7);
	adlist(arr, 6, 7);
	
	int count = 0;
	for (i = 0; i < SIZE; i++)
		if (arr[i] != NULL)
			count++;
	topSort(arr, result, count);


		printf("Topological sort의 결과: ");
		printf("\n");
	for (int i = 0; i < count; i++) {
		
		printf("Vetex %d ", result[i]);
		if (i < count - 1) {
			printf("->");
		}
	}
	

	
	return 0;
}


