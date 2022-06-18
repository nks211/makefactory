#include <stdio.h>
#include <stdlib.h>

int compare(int A, int B) {
	if (A > B)
		return 1;
	else if (A < B)
		return -1;
	else
		return 0;
}

typedef struct term {
	float C;
	int E;
	struct term* nextterm;
}term;

typedef struct headnode {
	term* head;
}headnode;

headnode* createpolynomiallist() {
	headnode* firstnode;
	firstnode = (headnode*)malloc(sizeof(headnode));
	firstnode->head = NULL;
	return firstnode;
}

void insertnode(headnode* head, float c, int e) {
	term* newnode; term* first;
	newnode = (term*)malloc(sizeof(term));
	newnode->C = c;
	newnode->E = e;
	newnode->nextterm = NULL;
	if (head->head == NULL) {
		head->head = newnode;
		return;
	}
	else {
		first = head->head;
		while (first->nextterm != NULL) {
			first = first->nextterm;
		}
		first->nextterm = newnode;
	}
}

headnode* ADDpolynomiallist(headnode* A, headnode* B, headnode* C) {
	term* a = A->head; term* b = B->head;
	float sum;
	while (a && b) {
		switch (compare(a->E, b->E)) {
			case 1:
				insertnode(C, a->C, a->E);
				a = a->nextterm;
				break;
			case 0:
				sum = a->C + b->C;
				if (sum)
					insertnode(C, sum, a->E);
				a = a->nextterm; b = b->nextterm;
				break;
			case -1:
				insertnode(C, b->C, b->E);
				b = b->nextterm;
		}
	}
	for (; a != NULL; a = a->nextterm)
		insertnode(C, a->C, a->E);
	for (; b != NULL; b = b->nextterm)
		insertnode(C, b->C, b->E);
	return C;
}

void printlist(headnode* N) {
	term* node = N->head;
	while (node != NULL) {
		printf("%.0f %d ", node->C, node->E);
		node = node->nextterm;
	}
}

int main() {

	FILE* polynomialA; FILE* polynomialB;
	headnode* A = createpolynomiallist();
	headnode* B = createpolynomiallist();
	headnode* C = createpolynomiallist();

	fopen_s(&polynomialA, "a.txt", "r");
	fopen_s(&polynomialB, "b.txt", "r");
	int anumber, bnumber;
	fscanf_s(polynomialA, "%d", &anumber);
	fscanf_s(polynomialB, "%d", &bnumber);
	float coefficient; int exponent;
	for (int a = 1; a <= anumber; a++) {
		fscanf_s(polynomialA, "%f", &coefficient);
		fscanf_s(polynomialA, "%d", &exponent);
		insertnode(A, coefficient, exponent);
	}
	for (int b = 1; b <= bnumber; b++) {
		fscanf_s(polynomialB, "%f", &coefficient);
		fscanf_s(polynomialB, "%d", &exponent);
		insertnode(B, coefficient, exponent);
	}
	C = ADDpolynomiallist(A, B, C);
	printlist(C);
	fclose(polynomialA); fclose(polynomialB);

	return 0;

}