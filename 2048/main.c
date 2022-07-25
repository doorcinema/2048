#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <conio.h>

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
	size = (size_t)sqrt(size);

	return size;
}

void print_arr(int *arr, size_t size) {
	for (size_t i = 0; i < size * size; i++) {
		if (*(arr + i) == 0)
			printf("    ");
		else
			printf("%d", *(arr + i));
		if ((i + 1) % size == 0)
			printf("\n");
	}

	return;
}

int my_rand(size_t size) {
	int value = rand() % (int)size;
	return value;
}

void input_keyboard() {
	char c;

	while (1) {
		while (_kbhit()) {
			c = _getch();
			switch (c) {
			case 72:
				printf("UP\n");
				break;
			case 75:
				printf("LEFT\n");
				break;
			case 77:
				printf("RIGHT\n");
				break;
			case 80:
				printf("DOWN\n");
				break;
			}
		}
	}

	return;
}

int main(void) {
	srand((unsigned int)time(NULL));

	int *arr = make_arr();
	size_t size = arr_size(arr);
	size_t total_size = (size_t)pow((double)size, (double)2);

	for (size_t i = 0; i < size * size; i++)
		*(arr + i) = 0;

	print_arr(arr, size);

	input_keyboard();

	free(arr);
	return 0;
}