#define MAX_NUMBER 100
#include <stdio.h>

typedef struct element {
	int number;
	char letter;
}element;

void merge1(element mergingset[], element mergedset[], int start, int mergepoint, int finish) {
	int a = start; int b = mergepoint + 1;
	while (start <= mergepoint && b <= finish) {
		if (mergingset[start].number >= mergingset[b].number)
			mergedset[a++] = mergingset[start++];
		else
			mergedset[a++] = mergingset[b++];
	}
	if (start > mergepoint)
		for (int c = b; c <= finish; c++)
			mergedset[c] = mergingset[c];
	else
		for (int c = start; c <= mergepoint; c++)
			mergedset[a + c - start] = mergingset[c];
}

void merge2(element mergingset[], element mergedset[], int start, int mergepoint, int finish) {
	int a = start; int b = mergepoint + 1;
	while (start <= mergepoint && b <= finish) {
		if (mergingset[start].letter >= mergingset[b].letter)
			mergedset[a++] = mergingset[start++];
		else
			mergedset[a++] = mergingset[b++];
	}
	if (start > mergepoint)
		for (int c = b; c <= finish; c++)
			mergedset[c] = mergingset[c];
	else
		for (int c = start; c <= mergepoint; c++)
			mergedset[a + c - start] = mergingset[c];
}

void mergeletter1(element mergingset[], element mergedset[], int length, int size) {
	int a, d;
	for (a = 1; a <= length - 2 * size + 1; a += 2 * size) {
		merge1(mergingset, mergedset, a, a + size - 1, a + 2 * size - 1);
	}
	if (a + size - 1 < length) {
		merge1(mergingset, mergedset, a, a + size - 1, length);
	}
	else
		for (d = a; d <= length; d++)
			mergedset[d] = mergingset[d];
}

void mergeletter2(element mergingset[], element mergedset[], int length, int size) {
	int a, d;
	for (a = 1; a <= length - 2 * size + 1; a += 2 * size) {
		merge2(mergingset, mergedset, a, a + size - 1, a + 2 * size - 1);
	}
	if (a + size - 1 < length) {
		merge2(mergingset, mergedset, a, a + size - 1, length);
	}
	else
		for (d = a; d <= length; d++)
			mergedset[d] = mergingset[d];
}

void mergesort1(element letterset[], int length) {
	int size = 1;
	element changeletterset[MAX_NUMBER];
	while (size < length) {
		mergeletter1(letterset, changeletterset, length, size);
		size *= 2;
		mergeletter1(changeletterset, letterset, length, size);
		size *= 2;
	}
}

void mergesort2(element letterset[], int length) {
	int size = 1;
	element changeletterset[MAX_NUMBER];
	while (size < length) {
		mergeletter2(letterset, changeletterset, length, size);
		size *= 2;
		mergeletter2(changeletterset, letterset, length, size);
		size *= 2;
	}
}

int main() {

	FILE* multimergesortingset; FILE* multimergesortedset;

	fopen_s(&multimergesortingset, "in.txt", "r");
	element Elementset[MAX_NUMBER] = { NULL }; int i = 1;
	while (!feof(multimergesortingset)) {
		int number;
		fscanf_s(multimergesortingset, "%d", &number);
		Elementset[i].number = number;
		char letter = fgetc(multimergesortingset);
		Elementset[i].letter = letter;
		i++;
	}
	fclose(multimergesortingset);

	int j = 1; int k = 1;
	element NewElementset[MAX_NUMBER] = { NULL };
	while (Elementset[j].number && Elementset[j].letter) {
		if (j % 2 == 0) {
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
		mergesort1(NewElementset, k - 1);
	else
		mergesort2(NewElementset, k - 1);

	int l = 1;
	fopen_s(&multimergesortedset, "out.txt", "w");
	while (l < k) {
		printf("%d %c\n", NewElementset[l].number, NewElementset[l].letter);
		fprintf_s(multimergesortedset, "%d ", NewElementset[l].number);
		fprintf_s(multimergesortedset, "%c\n", NewElementset[l].letter);
		l++;
	}
	fclose(multimergesortedset);

	return 0;

}