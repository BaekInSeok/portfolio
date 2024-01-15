#include <stdio.h>
#include <time.h>
#include <Windows.h>

int search_binary2(int *list, int key, int low, int high) {
	int middle;

	while (low <= high) {
		middle = (low + high) / 2;
		if (key == list[middle])
			return middle;
		else if (key > list[middle])
			low = middle + 1;
		else
			high = middle - 1;
	}
	return -1;
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

	printf("찾고자 하는 정수를 입력하세요");
	scanf("%d", &scan);

	start = clock();
	i = search_binary2(list, scan, 0, count);
	end = clock();
	if (i != -1) {
		printf("<탐색성공>\n%d 번째에 저장되어있음\n", i);
		printf("타이머 : %f\n", ((float)(end - start) / CLOCKS_PER_SEC));
	}
	else printf("탐색실패\n");
}