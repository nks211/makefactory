#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
	int data;
	struct listnode* nextdata;
}listnode;

typedef struct headnode {
	struct listnode* head;
}headnode;

headnode* createlist() {
	headnode* firstnode;
	firstnode = (headnode*)malloc(sizeof(headnode));
	firstnode->head = NULL;
	return firstnode;
}

void insertnode(headnode* H, int number) {
	listnode* newnode; listnode* first;
	newnode = (listnode*)malloc(sizeof(listnode));
	newnode->data = number;
	newnode->nextdata = NULL;
	if (H->head == NULL) {
		H->head = newnode;
		return;
	}
	else {
		first = H->head;
		while (first->nextdata != NULL)
			first = first->nextdata;
		first->nextdata = newnode;
	}
}

void printlist(headnode* N) {
	listnode* node = N->head;
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->nextdata;
	}
	printf("\n");
}

int main() {

	FILE* adjacencynumber;

	fopen_s(&adjacencynumber, "in.txt", "r");
	int Matrix[6][6];
	for (int a = 1; a <= 5; a++) {
		for (int b = 1; b <= 5; b++)
			Matrix[a][b] = 0;
	}
	int i, j;
	while (!feof(adjacencynumber)) {
		fscanf_s(adjacencynumber, "%d", &i);
		fscanf_s(adjacencynumber, "%d", &j);
		Matrix[i][j] = 1; Matrix[j][i] = 1;
	}
	fclose(adjacencynumber);
	for (int m = 1; m <= 5; m++) {
		for (int n = 1; n <= 5; n++) {
			printf("%d ", Matrix[m][n]);
		}
		printf("\n");
	}

	headnode* H1 = createlist();
	headnode* H2 = createlist();
	headnode* H3 = createlist();
	headnode* H4 = createlist();
	headnode* H5 = createlist();

	for (int c = 1; c <= 5; c++) {
		if (Matrix[1][c] != 0)
			insertnode(H1, c);
		if (Matrix[2][c] != 0)
			insertnode(H2, c);
		if (Matrix[3][c] != 0)
			insertnode(H3, c);
		if (Matrix[4][c] != 0)
			insertnode(H4, c);
		if (Matrix[5][c] != 0)
			insertnode(H5, c);
	}

	printf("v1: "); printlist(H1);
	printf("v2: "); printlist(H2);
	printf("v3: "); printlist(H3);
	printf("v4: "); printlist(H4);
	printf("v5: "); printlist(H5);

	return 0;
}