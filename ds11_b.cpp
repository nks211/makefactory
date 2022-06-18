#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
	int number;
	listnode* nextnode;
}listnode;

typedef struct headnode {
	listnode* head;
}headnode;

headnode* createlinkedlist() {
	headnode* firstnode;
	firstnode = (headnode*)malloc(sizeof(headnode));
	firstnode->head = NULL;
	return firstnode;
}

void insertnode(headnode* head, int N) {
	listnode* firstnode; listnode* newnode;
	newnode = (listnode*)malloc(sizeof(listnode));
	newnode->number = N;
	newnode->nextnode = NULL;
	if (head->head == NULL) {
		head->head = newnode;
		return;
	}
	else {
		firstnode = head->head;
		while (firstnode->nextnode != NULL)
			firstnode = firstnode->nextnode;
		firstnode->nextnode = newnode;
	}
}

void printlist(headnode* H) {
	listnode* node = H->head;
	while (node != NULL) {
		printf("%d(%d)\n",node->number, node);
		node = node->nextnode;
	}
}

int main() {

	int nodenumber;
	printf("정수 입력: ");
	scanf_s("%d", &nodenumber);
	headnode* List = createlinkedlist();
	for (int i = 0; i < nodenumber; i++) {
		insertnode(List, i);
	}
	printlist(List);

	return 0;

}