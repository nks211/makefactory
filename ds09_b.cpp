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

bool isnumberinlist(headnode* list, int number) {
	node* presentnode = (node*)malloc(sizeof(node));
	presentnode = list->first;
	while (presentnode->nextnode != NULL) {
		if (presentnode->number == number) {
			return false;
		}
		else {
			presentnode = presentnode->nextnode;
		}
	}
	return true;
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

void descendorder(headnode* list) {
	node* N = (node*)malloc(sizeof(node));
	node* NN = (node*)malloc(sizeof(node));
	N = list->first; NN = N->nextnode;
	while (N != NULL && NN != NULL) {
		if (N->number < NN->number) {
			int temp = NN->number;
			NN->number = N->number;
			N->number = temp;
		}
		N = NN;
		NN = NN->nextnode;
	}
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

	headnode* linkedlist; int N;
	linkedlist = createnodelist();
	printf("정수 입력: ");
	scanf_s("%d", &N);
	if (N != -1){
		insertnode(linkedlist, linkedlist->first, N);
		printlist(linkedlist);
		printf("정수 입력: ");
		scanf_s("%d", &N);
	}
	while (N != -1) {
		if (isnumberinlist(linkedlist, N)) {
			insertnode(linkedlist, linkedlist->first, N);
			descendorder(linkedlist);
		}
		printlist(linkedlist);
		printf("정수 입력: ");
		scanf_s("%d", &N);
	}

	return 0;

}