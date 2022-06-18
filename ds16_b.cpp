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

void BFS(int start, headnode** adjlist, bool* visited) {
	visited[start] = true;
	printf("%d ", start);
	headnode* Queue = createlist();
	insertnode(Queue, start);
	listnode* node = Queue->head;
	int list = start;
	while (node) {
		for (listnode* nodenumber = adjlist[list]->head; nodenumber; nodenumber = nodenumber->nextnumber) {
			if (!visited[nodenumber->number]) {
				insertnode(Queue, nodenumber->number);
				printf("%d ", nodenumber->number);
				visited[nodenumber->number] = true;
			}
		}
		node = node->nextnumber; 
		if(node)
			list = node->number;
	}
}

int main() {

	FILE* BFSnumber;

	fopen_s(&BFSnumber, "in.txt", "r");
	int vertices;
	fscanf_s(BFSnumber, "%d", &vertices);
	headnode** adjlist = (headnode**)malloc(sizeof(headnode*) * (vertices + 1));
	for (int a = 1; a <= vertices; a++)
		adjlist[a] = createlist();
	int x = 2; int y = 1; int adjected;
	while (!feof(BFSnumber)) {
		fscanf_s(BFSnumber, "%d", &adjected);
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
	fclose(BFSnumber);

	int startvertex;
	bool* visited = (bool*)malloc(sizeof(bool) * (vertices + 1));
	for (int b = 1; b <= vertices; b++)
		visited[b] = false;
	printf("시작점 입력 : ");
	scanf_s("%d", &startvertex);
	while (startvertex >= 1 && startvertex <= vertices) {
		BFS(startvertex, adjlist, visited);
		printf("\n");
		for (int b = 1; b <= vertices; b++)
			visited[b] = false;
		printf("시작점 입력 : ");
		scanf_s("%d", &startvertex);
	}

	return 0;

}