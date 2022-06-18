#define MAX_NUMBER 100
#include <stdio.h>
#include <stdlib.h>

int Maxheap[MAX_NUMBER];
int pointer = 0;

void push(int number, int pointer) {
	int i;
	if (pointer >= MAX_NUMBER - 1) {
		fprintf(stderr, "Full Max Heap\n");
		exit(1);
	}
	i = ++pointer;
	while (i != 1 && number > Maxheap[i / 2]) {
		Maxheap[i] = Maxheap[i / 2];
		i /= 2;
	}
	Maxheap[i] = number;
}

int pop(int pointer) {
	if (pointer < 0) {
		fprintf(stderr, "Empty Max Heap\n");
		exit(1);
	}
	int number = Maxheap[1];
	int changenumber = Maxheap[pointer--];
	int parent = 1; int child = 2;
	while (child <= pointer) {
		if (child < pointer && Maxheap[child] < Maxheap[child + 1])
			child++;
		if (changenumber >= Maxheap[child]) break;
		Maxheap[parent] = Maxheap[child];
		parent = child; child *= 2;
	}
	Maxheap[parent] = changenumber;
	return number;
}

int main() {

	FILE* heapnumber;

	fopen_s(&heapnumber, "in.txt", "r");
	int heapnode;
	while (!feof(heapnumber)) {
		fscanf_s(heapnumber, "%d", &heapnode);
		push(heapnode, pointer++);
	}
	fclose(heapnumber);
	for (int i = 1; Maxheap[i]; i++)
		printf("%d ", Maxheap[i]);
	printf("\n");
	printf("정수 입력 : ");
	scanf_s("%d", &heapnode);
	for (int j = 1; j <= heapnode; j++)
		int maxnumber = pop(pointer--);
	for (int k = 1; k <= pointer; k++)
		printf("%d ", Maxheap[k]);
	printf("\n");
	return 0;

}