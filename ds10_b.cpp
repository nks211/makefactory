#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int number;
	struct node* nextnode;
}node;

typedef struct headnode {
	node* first;
}headnode;

headnode* createnodelist() {
	headnode* firstnode = (headnode*)malloc(sizeof(headnode));
	firstnode->first = NULL;
	return firstnode;
}

void insertnode(headnode* head, node* parentnode, int number) {
	node* newnode; node* startnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->number = number;
	if (head->first == NULL) {
		newnode->nextnode = NULL;
		head->first = newnode;
	}
	else {
		newnode->nextnode = parentnode->nextnode;
		parentnode->nextnode = newnode;
	}
}

void ascendorder(headnode* list) {
	node* N = (node*)malloc(sizeof(node));
	node* NN = (node*)malloc(sizeof(node));
	N = list->first; NN = N->nextnode;
	while (N != NULL && NN != NULL) {
		if (N->number > NN->number) {
			int temp = NN->number;
			NN->number = N->number;
			N->number = temp;
		}
		N = NN;
		NN = NN->nextnode;
	}
}

headnode* intersectlist(headnode* A, headnode* B) {
	headnode* C = createnodelist();
	C->first = NULL;
	node* a = A->first;
	node* b = B->first;
	while (a != NULL && b != NULL) {
		if (a->number < b->number) {
			a = a->nextnode;
		}
		else if (a->number > b->number) {
			b = b->nextnode;
		}
		else {
			insertnode(C, C->first, a->number);
			ascendorder(C);
			a = a->nextnode; b = b->nextnode;
		}
	}
	return C;
}

void printlist(headnode* H) {
	node* step = H->first;
	while (step != NULL) {
		printf("%d ", step->number);
		step = step->nextnode;
	}
	printf("\n");
}

int main() {

	FILE* first; FILE* second;
	fopen_s(&first, "in1.txt", "r");
	fopen_s(&second, "in2.txt", "r");
	headnode* Aset = (headnode*)malloc(sizeof(headnode));
	headnode* Bset = (headnode*)malloc(sizeof(headnode));
	Aset->first = NULL; Bset->first = NULL;
	int anumber, bnumber;
	fscanf_s(first, "%d", &anumber);
	fscanf_s(second, "%d", &bnumber);
	insertnode(Aset, Aset->first, anumber);
	insertnode(Bset, Bset->first, bnumber);
	while (!feof(first)) {
		fscanf_s(first, "%d", &anumber);
		insertnode(Aset, Aset->first, anumber);
		ascendorder(Aset);
	}
	while (!feof(second)) {
		fscanf_s(second, "%d", &bnumber);
		insertnode(Bset, Bset->first, bnumber);
		ascendorder(Bset);
	}
	fclose(first); fclose(second);
	printf("A: "); printlist(Aset);
	printf("B: "); printlist(Bset);
	printf("Intersection: "); printlist(intersectlist(Aset, Bset));

	return 0;

}