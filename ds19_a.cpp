#define MAX_NUMBER 100
#include <stdio.h>

void merge(char mergingset[], char mergedset[], int start, int mergepoint, int finish) {
	int a = start; int b = mergepoint + 1;
	while (start <= mergepoint && b <= finish) {
		if (mergingset[start] >= mergingset[b])
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

void mergeletter(char mergingset[], char mergedset[], int length, int size) {
	int a, d;
	for (a = 1; a <= length - 2 * size + 1; a += 2 * size) {
		merge(mergingset, mergedset, a, a + size - 1, a + 2 * size - 1);
	}
	if (a + size - 1 < length) {
		merge(mergingset, mergedset, a, a + size - 1, length);
	}
	else
		for (d = a; d <= length; d++)
			mergedset[d] = mergingset[d];
}

void mergesort(char letterset[], int length) {
	int size = 1;
	char changeletterset[MAX_NUMBER];
	while (size < length) {
		mergeletter(letterset, changeletterset, length, size);
		size *= 2;
		mergeletter(changeletterset, letterset, length, size);
		size *= 2;
	}
}

int main() {

	FILE* mergesortingletter; FILE* mergesortedletter;

	fopen_s(&mergesortingletter, "in.txt", "r");
	char Letterset[MAX_NUMBER] = { NULL }; int i = 1;
	while (!feof(mergesortingletter)) {
		char letter = fgetc(mergesortingletter);
		if (letter != '\n')
			Letterset[i++] = letter;
	}
	fclose(mergesortingletter);

	mergesort(Letterset, --i);

	int j = 1;
	fopen_s(&mergesortedletter, "out.txt", "w");
	while (Letterset[j] != NULL) {
		printf("%c\n", Letterset[j]);
		fprintf_s(mergesortedletter, "%c\n", Letterset[j]);
		j++;
	}
	fclose(mergesortedletter);

	return 0;

}