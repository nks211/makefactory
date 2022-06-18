#define MAX_NUMBER 100
#include <stdio.h>

typedef struct element {
	int number;
	char letter;
}element;

void Heapsort1(element A[], int N) {
	for (int i = 1; i < N; ++i) {
		int childindex = i;
		do {
			int rootindex = childindex / 2;
			if (A[rootindex].number > A[childindex].number) {
				element item = A[childindex];
				A[childindex] = A[rootindex];
				A[rootindex] = item;
			}
			childindex = rootindex;
		} while (childindex != 0);
	}
	for(int j = N - 1; j >= 0; j--) {
		element maxitem = A[j];
		A[j] = A[0];
		A[0] = maxitem;
		int rootindex = 0; int childindex;
		do {
			childindex = 2 * rootindex + 1;
			if (childindex < j - 1 && A[childindex].number > A[childindex + 1].number)
				childindex++;
			if (childindex < j && A[rootindex].number > A[childindex].number) {
				element temp = A[childindex];
				A[childindex] = A[rootindex];
				A[rootindex] = temp;
			}
			rootindex = childindex;
		} while (childindex < j);
	}
}

void Heapsort2(element A[], int N) {
	for (int i = 1; i < N; ++i) {
		int childindex = i;
		do {
			int rootindex = childindex / 2;
			if (A[rootindex].letter > A[childindex].letter) {
				element item = A[childindex];
				A[childindex] = A[rootindex];
				A[rootindex] = item;
			}
			childindex = rootindex;
		} while (childindex != 0);
	}
	for (int j = N - 1; j >= 0; j--) {
		element maxitem = A[j];
		A[j] = A[0];
		A[0] = maxitem;
		int rootindex = 0; int childindex;
		do {
			childindex = 2 * rootindex + 1;
			if (childindex < j - 1 && A[childindex].letter > A[childindex + 1].letter)
				childindex++;
			if (childindex < j && A[rootindex].letter > A[childindex].letter) {
				element temp = A[childindex];
				A[childindex] = A[rootindex];
				A[rootindex] = temp;
			}
			rootindex = childindex;
		} while (childindex < j);
	}
}

int main() {

	FILE* multiheapsortingset; FILE* multiheapsortedset;

	fopen_s(&multiheapsortingset, "in.txt", "r");
	element Elementset[MAX_NUMBER] = { NULL }; int i = 0;
	while (!feof(multiheapsortingset)) {
		int number;
		fscanf_s(multiheapsortingset, "%d", &number);
		Elementset[i].number = number;
		char letter = fgetc(multiheapsortingset);
		Elementset[i].letter = letter;
		i++;
	}
	fclose(multiheapsortingset);

	int j = 0; int k = 0;
	element NewElementset[MAX_NUMBER] = { NULL };
	while (Elementset[j].number && Elementset[j].letter) {
		if (j % 2 == 1) {
			NewElementset[k].number = Elementset[j].number;
			NewElementset[k].letter = Elementset[j].letter;
			k++;
		}
		j++;
	}

	int choice;
	printf("정렬 기준 : ");
	scanf_s("%d", &choice);
	if (choice == 1)
		Heapsort1(NewElementset, k);
	else
		Heapsort2(NewElementset, k);

	int l = 0;
	fopen_s(&multiheapsortedset, "out.txt", "w");
	while (l < k) {
		printf("%d %c\n", NewElementset[l].number, NewElementset[l].letter);
		fprintf_s(multiheapsortedset, "%d ", NewElementset[l].number);
		fprintf_s(multiheapsortedset, "%c\n", NewElementset[l].letter);
		l++;
	}
	fclose(multiheapsortedset);

	return 0;

}