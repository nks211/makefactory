#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
	int number;
	struct listnode* nextnumber;
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

void insertnode(headnode* head, int number) {
	listnode* newnode; listnode* first;
	newnode = (listnode*)malloc(sizeof(listnode));
	newnode->number = number;
	newnode->nextnumber = NULL;
	if (head->head == NULL) {
		head->head = newnode;
		return;
	}
	else {
		first = head->head;
		while (first->nextnumber != NULL)
			first = first->nextnumber;
		first->nextnumber = newnode;
	}
}

void DFS(int start, headnode** adjlist, bool* visited) {
	visited[start] = true;
	listnode* node;
	for (node = adjlist[start]->head; node; node = node->nextnumber) {
		if (!visited[node->number])
			DFS(node->number, adjlist, visited);
	}
}

void P1() {
	
	FILE* connectednumber;

	fopen_s(&connectednumber, "in.txt", "r");
	int vertices;
	fscanf_s(connectednumber, "%d", &vertices);
	headnode** adjlist = (headnode**)malloc(sizeof(headnode*) * (vertices + 1));
	for (int a = 1; a <= vertices; a++)
		adjlist[a] = createlist();
	int x = 2; int y = 1; int adjected;
	while (!feof(connectednumber)) {
		fscanf_s(connectednumber, "%d", &adjected);
		if (adjected) {
			insertnode(adjlist[x], y);
			insertnode(adjlist[y], x);
		}
		if (y == x - 1) {
			x++; y = 1;
		}
		else
			y++;
	}
	fclose(connectednumber);

	printf("문제 1: ");
	bool* visited = (bool*)malloc(sizeof(bool) * (vertices + 1));
	for (int b = 1; b <= vertices; b++)
		visited[b] = false;
	int connectedcomponents = 0;
	for (int index = 1; index <= vertices; index++) {
		if (!visited[index]) {
			DFS(index, adjlist, visited);
			connectedcomponents++;
		}
	}
	printf("%d\n", connectedcomponents);

}

void P2() {

	FILE* checkcyclenumber;

	fopen_s(&checkcyclenumber, "in.txt", "r");
	int vertices;
	fscanf_s(checkcyclenumber, "%d", &vertices);
	headnode** adjlist = (headnode**)malloc(sizeof(headnode*) * (vertices + 1));
	for (int a = 1; a <= vertices; a++)
		adjlist[a] = createlist();
	int x = 2; int y = 1; int adjected;
	while (!feof(checkcyclenumber)) {
		fscanf_s(checkcyclenumber, "%d", &adjected);
		if (adjected) {
			insertnode(adjlist[x], y);
			insertnode(adjlist[y], x);
		}
		if (y == x - 1) {
			x++; y = 1;
		}
		else
			y++;
	}
	fclose(checkcyclenumber);

	printf("문제 2: ");
	bool* visited = (bool*)malloc(sizeof(bool) * (vertices + 1));
	for (int b = 1; b <= vertices; b++)
		visited[b] = false;
	int* checked = (int*)malloc(sizeof(int) * (vertices + 1));
	for (int c = 1; c <= vertices; c++)
		checked[c] = c;
	char result = 'n';
	for (int d = 1; d <= vertices; d++) {
		if (!visited[d])
			DFS(d, adjlist, visited);
		headnode* line = adjlist[d];
		listnode* node = line->head;
		while (node != NULL) {
			if (node->number != checked[d] && checked[node->number] == checked[d]) {
				result = 'y';
			}
			if (visited[node->number]) {
				checked[node->number] = d;
			}
			node = node->nextnumber;
		}
	}
	printf("%c\n", result);
}

int main() {

	P1();
	P2();

	return 0;

}