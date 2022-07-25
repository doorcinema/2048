#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>

int *make_arr() {
	int size;
	int *arr = NULL;

	while (1) {
		printf("사이즈를 입력해주세요 (n * n) : ");
		scanf("%d", &size);

		if (size < 1) {
			printf("0보다 큰 정수를 입력해주세요.\n");
			while (getchar() != '\n');
			system("pause");
			system("cls");
			continue;
		}

		arr = (int *)malloc(sizeof(int) * size * size);

		if (arr == NULL) {
			printf("MALLOC FAILED\n");
			system("pause");
			exit(1);
		}
		else
			break;
	}

	return arr;
}

size_t arr_size(int *arr) {
	size_t size = _msize((int *)arr) / sizeof(*arr);
	return size;
}

int main(void) {
	int *arr = make_arr();
	size_t size = arr_size(arr);

	free(arr);
	return 0;
}