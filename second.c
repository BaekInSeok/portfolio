#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ( (t) = (x), (x)=(y) , (y) = (t) )

typedef int element;
typedef struct {
	int *data;
	int front, rear;
}QueueType;

void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType *q, int n)
{
	q->front = q->rear = 0;
	q->data = malloc(sizeof(int) * n);

}

int is_empty(QueueType *q)
{
	return (q->front == q->rear);
}

int is_full(QueueType *q, int n)
{
	return ((q->rear + 1) % n== q->front);
}

void enqueue(QueueType *q, element item, int n)
{
	if (is_full(q, n)) {
		error("큐가 포화상태입니다");
	}
	q->rear = (q->rear + 1) % n;
	q->data[q->rear] = item;
}

element dequeue(QueueType *q, int n)
{
	if (is_empty(q)) {
		error("큐가 공백상태 입니다");
	}
	q->front = (q->front + 1) % n;
	return q->data[q->front];
}

void selection_sort(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);
	}
}

void radix_sort(int list[], int c, int DIGITS)
{
	int i, b, d, factor = 1;
	int j = 0;
	int count = 0;

	QueueType* queues = malloc(c * sizeof(QueueType));

	for (b = 0; b < c; b++) init_queue(&queues[b], c);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < c; i++) {
			enqueue(&queues[(list[i] / factor) % 10], list[i], c);
		}

		for (b = i = 0; b < c; b++) {
			while (!is_empty(&queues[b]))
			{
				list[i++] = dequeue(&queues[b], c);
			}
		}


		factor *= 10;
		for (i = 0; i < c; i++) {
			for (j = 0; j < c; j++) {
				queues[i].data[j] = -1;
			}
		}
	}
}



int main(void) {
	FILE *fp;
	int count = 0;
	int for_count = 0;
	int i = 0;
	int n = 0;
	int a = 0;
	int max = 0;
	clock_t start, end;

	fp = fopen("data3.txt", "r");
	if (fp == NULL) {
		printf("파일 못읽음");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &for_count);
		count++;
	}
	fclose(fp);
	int *list = malloc(sizeof(int) * count);

	fp = fopen("data3.txt", "r");
	if (fp == NULL) {
		printf("파일 못읽음");
		return 0;
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &list[i]);
		i++;
	}

	for (i = 0; i < count; i++) {
		a = 0;
		n = list[i];
		while (n > 0) {
			a++;
			n = n / 10;
		}
		if (a > max) {
			max = a;
		}
	}

	/*for (i = 0; i < count; i++) {
		printf("%d ", list[i]);
	}*/

	start = clock();
	radix_sort(list, count, max);
	end = clock();
	printf("\n기수정렬\n정렬 후 \n");
	/*for (i = 0; i < count; i++) {
		printf("%d ", list[i]);
	}*/
	printf("\ntimer  : %.2f\n", ((float)(end - start) / CLOCKS_PER_SEC));

	
	rewind(fp);
	i = 0;
	while (!feof(fp)) {
		fscanf(fp, "%d", &list[i]);
		i++;
	}
	printf("\n선택정렬\n");
	start = clock();
	selection_sort(list, count);
	end = clock();
	/*for (i = 0; i < count; i++) {
		printf("%d ", list[i]);
	}*/
	printf("\ntimer  : %.2f\n", ((float)(end - start) / CLOCKS_PER_SEC));

	
	fclose(fp);

}