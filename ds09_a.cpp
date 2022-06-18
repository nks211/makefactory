#include <stdio.h>
#include <stdlib.h>

struct pointer{
	struct pointer *nextnode;
	int number;
};

pointer* head = (pointer*)malloc(sizeof(pointer));

void insertnode(struct pointer *step, int newnumber) {
	pointer* newnode = (pointer*)malloc(sizeof(struct pointer));
	newnode->number = newnumber;
	if (head == NULL) {
		newnode->nextnode = NULL;
		head = newnode;
	}
	else {
		newnode->nextnode = step->nextnode;
		step->nextnode = newnode;
	}
}

void printlist(pointer* element) {
	pointer* node = element;
	while (node != NULL) {
		printf("%d ", node->number);
		node = node->nextnode;
	}
}

bool isnumberinlist(int N) {
	pointer* stepnode = (pointer*)malloc(sizeof(pointer));
	stepnode = head->nextnode;
	if (stepnode->number == N)
		return false;
	else {
		stepnode = stepnode->nextnode;
		while (stepnode != NULL) {
			if (stepnode->number == N)
				return false;
			else
				stepnode = stepnode->nextnode;
		}
		return true;
	}
}

void P1() {
	printf("문제 1: ");
	FILE* firstfile;
	fopen_s(&firstfile, "in1.txt", "r");
	int number;
	head->nextnode = NULL;
	pointer* stepnode = (pointer*)malloc(sizeof(pointer));
	stepnode = head;
	fscanf_s(firstfile, "%d", &number);
	insertnode(stepnode, number);
	stepnode = stepnode->nextnode;
	while (!feof(firstfile)) {
		fscanf_s(firstfile, "%d", &number);
		if (isnumberinlist(number)) {
			insertnode(stepnode, number);
			stepnode = stepnode->nextnode;
		}
	}
	if(isnumberinlist(number))
		insertnode(stepnode, number);
	fclose(firstfile);
	printlist(head->nextnode);
	printf("\n");
}

void P2() {
	printf("문제 2: ");
	FILE* secondfile;
	fopen_s(&secondfile, "in2.txt", "r");
	int number;
	head->nextnode = NULL;
	while (!feof(secondfile)) {
		fscanf_s(secondfile, "%d", &number);
		insertnode(head, number);
	}
	fclose(secondfile);
	printlist(head->nextnode);
}

int main() {

	P1();
	P2();

	return 0;

}