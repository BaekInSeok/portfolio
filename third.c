#include <stdio.h>
#include <time.h>
#include <Windows.h>

	
int seq_search(int *list, int key, int low, int high) {
	int i;
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;
	return -1;
}

int seq_search2(int *list, int key, int low, int high)
{
	int i;
	list[high + 1] = key;
	for (i = low; list[i] != key; i++)
		;
	if (i == (high + 1)) return -1;
	else return i;
}

int main(void) {
	int *list;
	int i = 0;
	int dummy = 0;
	int count = 0;
	int scan = 0;
	clock_t start, end;
	int a = 0;
	FILE *fp = fopen("data1.txt", "r");
	if (fp == NULL) {
		printf("파일못염");
		return 0;
	}

	while (!feof(fp)) {
		fscanf(fp, "%d", &dummy);
		count++;
	}
	fclose(fp);
	list = (int *)malloc(sizeof(int) *count);
	fp = fopen("data1.txt", "r");
	if (fp == NULL) {
		printf("파일못염");
		return 0;
	}
	while (!feof(fp)) {
		fscanf(fp, "%d", &list[i]);
		i++;
	}
	fclose(fp);

	printf(">> 데이터 개수:%d\n", count);
	printf("찾고자 하는 정수를 입력하세요");
	scanf("%d", &scan);

	start = clock();
	a = seq_search(list, scan, 0, count-1);
	if (a == -1) printf("실패\n");
	else printf("성공\n");
	end = clock();
	printf("타이머 : %.2f\n", ((float)(end - start) / CLOCKS_PER_SEC));

	start = clock();
	a = seq_search2(list, scan, 0, count-1);
	if (a == -1) printf("실패\n");
	else printf("성공\n");
	end = clock();
	printf("타이머 : %f\n", ((float)(end - start) / CLOCKS_PER_SEC));

}