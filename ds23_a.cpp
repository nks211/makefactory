#include <stdio.h>
#include <stdlib.h>

void heapify(int numberset[], int rootnumber, int N) {
	int pivot = numberset[rootnumber];
	int childindex = 2 * rootnumber;
	while (childindex <= N) {
		if (childindex < N && numberset[childindex] > numberset[childindex + 1])
			childindex++;
		if (pivot < numberset[childindex])
			break;
		else {
			numberset[childindex / 2] = numberset[childindex];
			childindex *= 2;
		}
		numberset[childindex / 2] = pivot;
	}
}

void Heapsort(int numberset[], int N) {
	for (int i = N / 2; i > 0; i--)
		heapify(numberset, i, N);
	for (int i = N - 1; i > 0; i--) {
		int temp = numberset[i + 1];
		numberset[i + 1] = numberset[1];
		numberset[1] = temp;
		heapify(numberset, 1, i);
	}
	for (int l = 1; l <= N; l++)
		printf("%d ", numberset[l]);
	printf("\n");
}

void P1() {
	
	FILE* heapnumber;

	fopen_s(&heapnumber, "in1.txt", "r");
	int size;
	fscanf_s(heapnumber, "%d", &size);
	int* heap = (int*)malloc(sizeof(int) * (size + 1));
	int index = 1;
	while (!feof(heapnumber)) {
		fscanf_s(heapnumber, "%d", &heap[index++]);
	}
	fclose(heapnumber);
	printf("문제 1 : ");
	Heapsort(heap, size);

}

void Insertsort(int* numberset, int N) {
	for (int j = 2; j <= N; j++) {
		int pivot = numberset[j];
		numberset[0] = pivot;
		int k = j - 1;
		while (pivot > numberset[k]) {
			numberset[k + 1] = numberset[k];
			k--;
		}
		numberset[k + 1] = pivot;
	}
	for (int k = 1; k <= N; k++)
		printf("%d ", numberset[k]);
	printf("\n");
}

void P2() {

	FILE* insertnumber;

	fopen_s(&insertnumber, "in2.txt", "r");
	int size;
	fscanf_s(insertnumber, "%d", &size);
	int* insert = (int*)malloc(sizeof(int) * (size + 1));
	int index = 1;
	while (!feof(insertnumber)) {
		fscanf_s(insertnumber, "%d", &insert[index++]);
	}
	fclose(insertnumber);
	printf("문제 2 : ");
	Insertsort(insert, size);

}

int main() {

	P1();
	P2();

	return 0;

}