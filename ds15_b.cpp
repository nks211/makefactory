#include <stdio.h>
#include <stdlib.h>

void Weightedunion(int i, int j, int* array) {
	int count = array[i] + array[j];
	if (array[i] >= array[j]) {
		array[i] = j; array[j] = count;
	}
	else {
		array[j] = i; array[i] = count;
	}
}

int Collapsingfind(int i, int* array) {
	int root, before, after;
	root = i;
	while (array[root] >= 0)
		root = array[root];
	for (before = i; before != root; before = after) {
		after = array[before];
		array[before] = root;
	}
	return root;
}

void printunionarray(char c, int a, int b, int n, int* array) {
	printf("%c %d %d : ", c, a, b);
	for (int index = 0; index <= n; index++)
		printf("%d ", array[index]);
	printf("\n");
}

void printfindarray(char c, int a, int n, int* array) {
	printf("%c %d : ", c, a);
	for (int index = 0; index <= n; index++)
		printf("%d ", array[index]);
	printf("\n");
}

int main() {

	FILE* unionnumber;

	fopen_s(&unionnumber, "in.txt", "r");
	int vertices;
	fscanf_s(unionnumber, "%d", &vertices);
	int* rootarray = (int*)malloc(sizeof(int) * (vertices + 1));
	for (int i = 0; i <= vertices; i++)
		rootarray[i] = -1;
	char selector; int uniona, unionb, find;
	while (!feof(unionnumber)) {
		fgetc(unionnumber);
		fscanf_s(unionnumber, "%c", &selector);
		if (selector == 'U') {
			fscanf_s(unionnumber, "%d", &uniona);
			fscanf_s(unionnumber, "%d", &unionb);
			Weightedunion(uniona, unionb, rootarray);
			printunionarray(selector, uniona, unionb, vertices, rootarray);
		}
		else {
			fscanf_s(unionnumber, "%d", &find);
			printfindarray(selector, find, vertices, rootarray);
			printf("%d\n", Collapsingfind(find, rootarray));
		}
	}
	fclose(unionnumber);

	return 0;

}