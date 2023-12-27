#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#pragma execution_character_Set("utf-8")

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )


//선택정렬
void selection_sort(char **list[], int n, char *temp) {

	int i, j, least;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i; j < n; j++)
			if (strcmp(list[least], list[j]) >= 0) least = j;
		SWAP(list[i], list[least], temp);
	}
}

//삽입정렬
void insertion_sort(char **list, int n, char *key)
{
	int i, j;
	for (i = 1; i < n; i++) {
		strcpy(key, list[i]);
		for (j = i - 1; j >= 0 && strcmp(list[j], key) > 0; j--)
			strcpy(list[j + 1], list[j]);
		strcpy(list[j + 1], key);
	}
}

//버블정렬
void bubble_sort(char **list, int n, char *temp)
{
	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			if (strcmp(list[j], list[j + 1]) > 0)
				SWAP(list[j], list[j + 1], temp);
	}
}

//쉘정렬
inc_insertion_sort(char **list, int first, int last, int gap, char *key) {
	int i, j;
	for (i = first + gap; i <= last; i = i + gap) {
		strcpy(key, list[i]);
		for (j = i - gap; j >= first && strcmp(list[j], key) > 0; j = j - gap)
			strcpy(list[j + gap], list[j]);
		strcpy(list[j + gap], key);
	}
}
void shell_sort(char **list, int n, char *temp) {
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap, temp);
	}
}

//합병 정렬
void merge(char **list, int left, int mid, int right, char **sorted)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	while (i <= mid && j <= right) {
		if (strcmp(list[j], list[i]) > 0) {
			strcpy(sorted[k++], list[i++]);
		}
		else if (strcmp(list[j], list[i]) <= 0)
			strcpy(sorted[k++], list[j++]);
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			strcpy(sorted[k++], list[l]);
	else
		for (l = i; l <= mid; l++)
			strcpy(sorted[k++], list[l]);
	for (l = left; l <= right; l++)
		strcpy(list[l], sorted[l]);
}
void merge_sort(char **list, int left, int right, char **sorted)
{
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid, sorted);
		merge_sort(list, mid + 1, right, sorted);
		merge(list, left, mid, right, sorted);
	}
}

//퀵정렬
int partition(char **list, int left, int right, char *pivot, char *temp)
{
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (strcmp(pivot, list[low]) > 0);
		do
			high--;
		while (strcmp(list[high], pivot) > 0);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(char **list, int left, int right, char *pivot, char *temp)
{
	if (left < right) {
		int q = partition(list, left, right, pivot, temp);
		quick_sort(list, left, q - 1, pivot, temp);
		quick_sort(list, q + 1, right, pivot, temp);
	}
}

//힙정렬
typedef struct {
	char *sentence;
}element;
typedef struct {
	element *heap;
	int heap_size;
}HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h, int n) {
	h->heap_size = 0;
	h->heap = (element *)malloc(sizeof(element)*n);
}
void insert_max_heap(HeapType*h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (strcmp(item.sentence, h->heap[i / 2].sentence) > 0)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && strcmp(h->heap[child + 1].sentence, (h->heap[child].sentence)) > 0)
			child++;
		if (strcmp(temp.sentence, h->heap[child].sentence) >= 0) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void heap_sort(element a[], int n) {

	int i;
	HeapType *h;
	h = create();
	init(h, n);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
	free(h);
}


int main(void) {
	SetConsoleOutputCP(65001);      //제대로 되는 정렬을 위해 코드페이지를 UTF-8로 변경.
	/**/element *element;           //힙정렬에쓰일 element구조체 배열을 선언.
	int count = 0;                  //리스트배열의 첫번째 인덱스 에 쓰이는 변수.
	char specimen[1000];            //count를 측정할때 쓰이는 변수.
	int max = 0;                    //문자열의 최대길이가 저장될 변수.
	int i = 0;                      //여러 반복문에 쓰일 변수.
	char a = 0;                     //txt에서 한글을 읽을때 필요한 변수.
	clock_t start, end;             //시간측정용.
	FILE *fp;                       //파일 읽기용 포인터.
	fp = fopen("text.txt", "r");    //text.txt를 읽기모드로 열기.
	if (fp == NULL) {               //만약 fp가 NULL이면
		printf("파일을 열지못함");  //파일을 열지 못했다고 출력 후
		return 0;                   //프로그램 종료.
	}
	while (!feof(fp)) {                 //파일의 끝까지
		fscanf(fp, "%s ", specimen);    //문장을 읽어와 specimen에 입력.
		if (max < strlen(specimen)) {   //max변수가 specimen의 길이보다 작으면
			max = strlen(specimen);     //max에 specimen의 길이대입.
		}
		count++;                        //문자열을 읽을때 마다 count가 1씩 증가.
	}
	rewind(fp);                         //fp의 읽는 위치를 처음으로 돌림.
	char **list;                        //동적으로 할당할 2차원 배열 ㅣist.
	char *temp;                         //정렬에서 문자열을 임시로 받을때 쓰이는 배열.
	char *temp2;                        //정렬에서 문자열을 임시로 받을때 쓰이는 배열2.
	char **sorted;                      //정렬에서 문자열을 임시로 받을때 쓰이는 이차원배열.
	list = (char **)malloc(sizeof(char*) *count);          //list의 첫번째 인덱스길이를 count로 할당.
	for (i = 0; i < count; i++) {
		list[i] = (char*)malloc(sizeof(char) * max);       //list의 두번째 인덱스길이룰 max로 할당.
	}
	temp = (char **)malloc(sizeof(char*) *max);            //temp의 인덱스길이를 max로 할당.
	temp2 = (char **)malloc(sizeof(char*) *max);           //temp2의 인덱스길이를 max로 할당.
	sorted = (char **)malloc(sizeof(char*) *count);        //sorted의 첫번째 인덱스길이를 count로 할당.
	for (i = 0; i < count; i++) {                          //sorted의 두번째 인덱스길이를 max로 할당.
		sorted[i] = (char*)malloc(sizeof(char) * max);     
	}
	/**/element = (char **)malloc(sizeof(char*) *count);   //구조채 element배열을 count만큼 할당.
	for (i = 0; i < count; i++) {
		element[i].sentence = (char*)malloc(sizeof(char) * max);//구조체 안의 배열의 길이를 max만큼할당.
	}
	

	i = 0;                                 //반복문에 쓰일 i를 0으로 초기화.
	a = fgetc(fp);                         //한글을 읽어오기위해 char을 3번 읽어옴.
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {                    //파일의 끝까지
		fscanf(fp, "%s", list[i]);         //list2차원 배열에 문자열들을 저장.
		i++;                               //i가 증가하며 반복.
	}
	rewind(fp);                            //fp의 읽는 위치를 처음으로 돌림.

	//////////////

	
	i = 0;
	a = fgetc(fp);
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {
		fscanf(fp, "%s", element[i].sentence);
		i++;
	}
	rewind(fp);

	////////////////


	printf("before%d\n", max);
	/*for (i = 0; i < count; i++) {
		printf("%s\n", list[i]);
	}*/

	printf("\n\n\n\n");
	printf("selection_sort\n");
	start = clock();
	selection_sort(list, count, temp);
	end = clock();
	
	printf("timer  : %.2f", ((float)(end - start) / CLOCKS_PER_SEC));
	///////////////////////////
	
	i = 0;
	a = fgetc(fp);
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {
		fscanf(fp, "%s", list[i]);
		i++;
	}
	rewind(fp);
	printf("\n\n\n\n");
	printf("insertion_sort\n");
	start = clock();
	insertion_sort(list, count, temp);
	end = clock();
	
	printf("timer  : %.2f", ((float)(end - start) / CLOCKS_PER_SEC));
	///////////////////////////
	
	i = 0;
	a = fgetc(fp);
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {
		fscanf(fp, "%s", list[i]);
		i++;
	}
	rewind(fp);
	printf("\n\n\n\n");
	printf("bubble_sort\n");
	start = clock();
	bubble_sort(list, count, temp);
	end = clock();
	
	printf("timer  : %.2f", ((float)(end - start) / CLOCKS_PER_SEC));
	///////////////////////////
	
	i = 0;
	a = fgetc(fp);
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {
		fscanf(fp, "%s", list[i]);
		i++;
	}
	rewind(fp);
	printf("\n\n\n\n");
	printf("shell_sort\n");
	start = clock();
	shell_sort(list, count, temp);
	end = clock();
	
	printf("timer  : %.2f", ((float)(end - start) / CLOCKS_PER_SEC));
	///////////////////////////
	
	i = 0;
	a = fgetc(fp);
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {
		fscanf(fp, "%s", list[i]);
		i++;
	}
	rewind(fp);
	printf("\n\n\n\n");
	printf("merrge_sort\n");
	start = clock();
	merge_sort(list, 0, count - 1, sorted);
	end = clock();
	
	printf("timer  : %.2f", ((float)(end - start) / CLOCKS_PER_SEC));
	///////////////////////////
	
	i = 0;
	a = fgetc(fp);
	a = fgetc(fp);
	a = fgetc(fp);
	while (!feof(fp)) {
		fscanf(fp, "%s", list[i]);
		i++;
	}
	fclose(fp);
	printf("\n\n\n\n");
	printf("quick_sort\n");
	start = clock();
	quick_sort(list, 0, count - 1, temp2, temp);
	end = clock();
	
	printf("timer  : %.2f", ((float)(end - start) / CLOCKS_PER_SEC));
	///////////////////////////
	printf("\n\n\n\n");
	printf("heap_sort\n");
	start = clock();
	heap_sort(element, count);
	end = clock();
	/*for (i = 0; i < count; i++) {
		printf("%s\n", element[i].sentence);
	}*/
	printf("timer : %.2f\n", ((float)(end - start) / CLOCKS_PER_SEC));

	return 0;
}