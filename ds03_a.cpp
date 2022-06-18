#include <stdio.h>
#include <time.h>
#include <malloc.h>

int COMPARE(int A, int B) {
	if (A < B)
		return -1;
	else if (A == B)
		return 0;
	else
		return 1;
}

int Recursive_Binary_Search(int* array, int search, int left, int right) {
	int mid = (left + right) / 2;
	if (left <= right) {
		switch (COMPARE(search, array[mid])) {
		case -1:
			return Recursive_Binary_Search(array, search, left, mid - 1);
		case 0:
			return mid;
		case 1:
			return Recursive_Binary_Search(array, search, mid + 1, right);
		}
	}
	else
		return -1;
}

int main() {

	FILE* searchfile;
	int N;

	fopen_s(&searchfile, "in.txt", "r");
	fscanf_s(searchfile, "%d", &N);

	int* array = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) {
		fscanf_s(searchfile, "%d", &array[i]);
	}

	clock_t start, finish;
	double elapsed;
	int search, index;
	printf("정수 입력: ");
	scanf_s("%d", &search);
	while (search >= 0) {
		start = clock();
		for (int i = 0; i < N; i++) {
			index = i;
			if (search == array[i]) {
				finish = clock();
				elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
				printf("Sequential: %d [%f ms]\n", i, elapsed * 1000);
				break;
			}
			else {
				index++;
			}
		}
		if (index == N) {
			finish = clock();
			elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
			printf("Sequential: %d [%f ms]\n", -1, elapsed * 1000);
		}

		start = clock();
		int left = 0, right = N - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			switch (COMPARE(search, array[mid])) {
				case -1:
					right = mid - 1;
					break;
				case 0:
					finish = clock();
					elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
					printf("Iterative: %d [%f ms]\n", mid, elapsed * 1000);
					break;
				case 1:
					left = mid + 1;
					break;
			}
			if (search == array[mid])
				break;
		}
		if (left > right) {
			finish = clock();
			elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
			printf("Iterative: %d [%f ms]\n", -1, elapsed * 1000);
		}

		start = clock();
		printf("Recursive: %d ", Recursive_Binary_Search(array, search, 0, N - 1));
		finish = clock();
		elapsed = ((double)finish - (double)start) / CLOCKS_PER_SEC;
		printf("[%f ms]\n", elapsed * 1000);

		printf("정수 입력: ");
		scanf_s("%d", &search);
	}

	fclose(searchfile);
	return 0;

}