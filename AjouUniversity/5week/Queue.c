#define MAX 12
#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[40];
	int volume;
} mail;

typedef struct
{
	mail heap[MAX + 1];
	int size;
} Queue;

void init(Queue* q)
{
	q->size = 0;
}
void enqueue(Queue* q, mail item)
{
	if (q->size == MAX)
	{
		printf("더이상 데이터를 추가할 수 없음");
		return;
	}

	q->size++;

	int i = q->size;
	while (i != 1 && item.volume > q->heap[i / 2].volume)
	{
		q->heap[i] = q->heap[i / 2];
		i /= 2;
	}
	q->heap[i] = item;
}
mail dequeue(Queue* q)
{
	if (q->size == 0)
	{
		printf("데이터가 존재하지 않습니다.");
		mail item;
		item.volume = -1;
		return item;
	}

	mail item = q->heap[1];
	mail tmp = q->heap[q->size--];
	int p = 1, c = 2;

	while (c <= q->size)
	{
		if (c < q->size && q->heap[c].volume < q->heap[c + 1].volume) c++;
		if (tmp.volume >= q->heap[c].volume) break;

		q->heap[p] = q->heap[c];
		p = c;
		c *= 2;
	}

	q->heap[p] = tmp;
	return item;
}
void sort(Queue* q)
{
	int i, size = q->size;
	Queue tmp;
	init(&tmp);
	for (i = 1; i <= size; i++) enqueue(&tmp, dequeue(q));
	for (i = 1; i <= size; i++) enqueue(q, dequeue(&tmp));
}
int removeItem(Queue* q, char* name)
{
	int index = -1, i;
	for (i = 1; i <= q->size; i++)
	{
		if (strcmp(q->heap[i].name, name) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1) return 0;

	q->heap[index] = q->heap[q->size--];
	sort(q);

	return index;
}


void insertItem();
void deleteItem();
void printItem();

Queue q;
int main()
{
	init(&q);
	while (1)
	{
		char menu;
		printf("\n삽입(i), 삭제(d), 출력(p): ");
		scanf("%c", &menu);

		getchar();

		if (menu == 'i') insertItem();
		else if (menu == 'd') deleteItem();
		else if (menu == 'p') printItem();
		else break;

	}

	return 0;
}


void insertItem()
{
	mail item;

	printf("처리할 데이터:");
	scanf("%[^\n]", item.name);
	getchar();

	printf("용량(단위:KB):");
	scanf("%d", &item.volume);
	getchar();

	enqueue(&q, item);
}
void deleteItem()
{
	char name[40];
	printf("삭제할 데이터:");
	scanf("%[^\n]", name);
	getchar();

	if (removeItem(&q, name))
	{
		printf("%s가 삭제됨\n", name);
	}
	else
	{
		printf("%s가 존재하지 않음\n", name);
	}
}
void printItem()
{
	Queue tmp;
	init(&tmp);

	while (q.size >= 1)
	{
		mail item = dequeue(&q);
		printf("%s-%dKB\n", item.name, item.volume);

		enqueue(&tmp, item);
	}
	while (tmp.size >= 1)
	{
		enqueue(&q, dequeue(&tmp));
	}
}
