#define MAX_NUMBER 100
#include <stdio.h>

typedef struct element {
	int number;
	char letter;
}element;

void QuickSort1(element a[], int left, int right) {
	int pivot; int i, j;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].number;
		do {
			do i++; while (a[i].number < pivot);
			do j--; while (a[j].number > pivot);
			if (i < j) {
				element item = a[j];
				a[j] = a[i]; a[i] = item;
			}
		} while (i < j);
		element item = a[j];
		a[j] = a[left]; a[left] = item;
		QuickSort1(a, left, j - 1);
		QuickSort1(a, j + 1, right);
	}
}

void QuickSort2(element a[], int left, int right) {
	char pivot; int i, j;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left].letter;
		do {
			do i++; while (a[i].letter < pivot);
			do j--; while (a[j].letter > pivot);
			if (i < j) {
				element item = a[j];
				a[j] = a[i]; a[i] = item;
			}
		} while (i < j);
		element item = a[j];
		a[j] = a[left]; a[left] = item;
		QuickSort2(a, left, j - 1);
		QuickSort2(a, j + 1, right);
	}
}

int main() {

	FILE* multisortingset; FILE* multisortedset;

	fopen_s(&multisortingset, "in.txt", "r");
	element Elementset[MAX_NUMBER] = { NULL }; int i = 0;
	while (!feof(multisortingset)) {
		int number;
		fscanf_s(multisortingset, "%d", &number);
		Elementset[i].number = number;
		char letter = fgetc(multisortingset);
		Elementset[i].letter = letter;
		i++;
	}
	fclose(multisortingset);

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
		QuickSort1(NewElementset, 0, k - 1);
	else
		QuickSort2(NewElementset, 0, k - 1);

	int l = 0;
	fopen_s(&multisortedset, "out.txt", "w");
	while (l < k) {
		printf("%d %c\n", NewElementset[l].number, NewElementset[l].letter);
		fprintf_s(multisortedset, "%d ", NewElementset[l].number);
		fprintf_s(multisortedset, "%c\n", NewElementset[l].letter);
		l++;
	}
	fclose(multisortedset);

	return 0;

}