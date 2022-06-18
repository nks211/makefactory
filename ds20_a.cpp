#define MAX_NUMBER 100
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
	int number;
	char letter;
}element;

int Mergelist1(element E[], int link[], int start1, int start2) {
	int last1, last2, checkpoint = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (E[last1].number >= E[last2].number) {
			link[checkpoint] = last1;
			checkpoint = last1; last1 = link[last1];
		}
		else {
			link[checkpoint] = last2;
			checkpoint = last2; last2 = link[checkpoint];
		}
	}
	if (last1 == 0)
		link[checkpoint] = last2;
	else
		link[checkpoint] = last1;
	return link[0];
}

int Mergelist2(element E[], int link[], int start1, int start2) {
	int last1, last2, checkpoint = 0;
	for (last1 = start1, last2 = start2; last1 && last2;) {
		if (E[last1].letter >= E[last2].letter) {
			link[checkpoint] = last1;
			checkpoint = last1; last1 = link[last1];
		}
		else {
			link[checkpoint] = last2;
			checkpoint = last2; last2 = link[checkpoint];
		}
	}
	if (last1 == 0)
		link[checkpoint] = last2;
	else
		link[checkpoint] = last1;
	return link[0];
}

int RecursiveMergeSort1(element E[], int link[], int left, int right) {
	if (left >= right) return left;
	int mid = (left + right) / 2;
	return Mergelist1(E, link, RecursiveMergeSort1(E, link, left, mid), RecursiveMergeSort1(E, link, mid + 1, right));
}

int RecursiveMergeSort2(element E[], int link[], int left, int right) {
	if (left >= right) return left;
	int mid = (left + right) / 2;
	return Mergelist2(E, link, RecursiveMergeSort2(E, link, left, mid), RecursiveMergeSort2(E, link, mid + 1, right));
}

int main() {

	FILE* recursivemergesortingset; FILE* recursivemergesortedset;

	fopen_s(&recursivemergesortingset, "in.txt", "r");
	element Elementset[MAX_NUMBER] = { NULL }; int i = 1;
	while (!feof(recursivemergesortingset)) {
		int number;
		fscanf_s(recursivemergesortingset, "%d", &number);
		Elementset[i].number = number;
		char letter = fgetc(recursivemergesortingset);
		Elementset[i].letter = letter;
		i++;
	}
	fclose(recursivemergesortingset);

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

	int choice; int* linkindex = (int*)malloc(sizeof(int) * k);
	for (int a = 1; a < k; a++)
		linkindex[a] = 0;
	printf("정렬 기준: ");
	scanf_s("%d", &choice);
	if (choice == 1) {
		int choice1;
		for (int step = 1; step < k; step++) {
			choice1 = RecursiveMergeSort1(NewElementset, linkindex, step, k - 1);
			element item = NewElementset[choice1];
			NewElementset[choice1] = NewElementset[step];
			NewElementset[step] = item;
			for (int a = 1; a < k; a++)
				linkindex[a] = 0;
		}
		for (int d = 1; d < k; d++)
			printf("%d %c\n", NewElementset[d].number, NewElementset[d].letter);
		fopen_s(&recursivemergesortedset, "out.txt", "w");
		int e = 1;
		while (e < k) {
			fprintf_s(recursivemergesortedset, "%d ", NewElementset[e].number);
			fprintf_s(recursivemergesortedset, "%c\n", NewElementset[e].letter);
			e++;
		}
		fclose(recursivemergesortedset);
	}
	else {
		int choice2;
		for (int step = 1; step < k; step++) {
			choice2 = RecursiveMergeSort2(NewElementset, linkindex, step, k - 1);
			element item = NewElementset[choice2];
			NewElementset[choice2] = NewElementset[step];
			NewElementset[step] = item;
			int nextstep = step; int beforestep = nextstep--;
			while (NewElementset[beforestep].letter == NewElementset[nextstep].letter) {
				if (NewElementset[nextstep].number > NewElementset[beforestep].number) {
					item = NewElementset[beforestep];
					NewElementset[beforestep] = NewElementset[nextstep];
					NewElementset[nextstep] = item;
					nextstep--; beforestep--;
				}
				else
					break;
			}
			for (int a = 1; a < k; a++)
				linkindex[a] = 0;
		}
		for (int d = 1; d < k; d++)
			printf("%d %c\n", NewElementset[d].number, NewElementset[d].letter);
		fopen_s(&recursivemergesortedset, "out.txt", "w");
		int e = 1;
		while (e < k) {
			fprintf_s(recursivemergesortedset, "%d ", NewElementset[e].number);
			fprintf_s(recursivemergesortedset, "%c\n", NewElementset[e].letter);
			e++;
		}
		fclose(recursivemergesortedset);
	}
	return 0;

}