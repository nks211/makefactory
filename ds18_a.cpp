#define MAX_NUMBER 100
#include <stdio.h>

void QuickSort(char a[], int left, int right) {
	char pivot; int i, j;
	if (left < right) {
		i = left; j = right + 1;
		pivot = a[left];
		do {
			do i++; while (a[i] < pivot);
			do j--; while (a[j] > pivot);
			if (i < j) {
				char item = a[j];
				a[j] = a[i]; a[i] = item;
			}
		} while (i < j);
		char item = a[j];
		a[j] = a[left]; a[left] = item;
		QuickSort(a, left, j - 1);
		QuickSort(a, j + 1, right);
	}
}

int main() {

	FILE* sortingletter; FILE* sortedletter;

	fopen_s(&sortingletter, "in.txt", "r");
	char Letterset[MAX_NUMBER] = { NULL }; int i = 0;
	while (!feof(sortingletter)) {
		char letter = fgetc(sortingletter);
		if(letter != '\n')
			Letterset[i++] = letter;
	}
	fclose(sortingletter);

	QuickSort(Letterset, 0, --i);

	int j = 0;
	fopen_s(&sortedletter, "out.txt", "w");
	while (Letterset[j] != NULL) {
		printf("%c\n", Letterset[j]);
		fprintf_s(sortedletter, "%c\n", Letterset[j]);
		j++;
	}
	fclose(sortedletter);

	return 0;

}