#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
	int key;
	struct listnode* nextlistnode;
}listnode;

typedef struct rootnode {
	listnode* root;
}rootnode;

rootnode* createnode() {
	rootnode* headnode = (rootnode*)malloc(sizeof(rootnode));
	headnode->root = NULL;
	return headnode;
}

void insertdivisionnode(rootnode** root, int keynumber, int bucketsize) {
	listnode* newnode = (listnode*)malloc(sizeof(listnode));
	newnode->key = keynumber; newnode->nextlistnode = NULL;
	int identifier = keynumber % bucketsize;
	if (root[identifier]->root == NULL) {
		root[identifier]->root = newnode;
		return;
	}
	else {
		listnode* firstnode = root[identifier]->root;
		while (firstnode->nextlistnode != NULL)
			firstnode = firstnode->nextlistnode;
		firstnode->nextlistnode = newnode;
		return;
	}
}

int searchnode(rootnode** root, int keynumber, int bucketsize) {
	int identifier = keynumber % bucketsize;
	listnode* searchnode = root[identifier]->root;
	while (searchnode) {
		if (searchnode->key == keynumber)
			return identifier;
		else
			searchnode = searchnode->nextlistnode;
	}
	return -1;
}

void printnode(rootnode* root) {
	listnode* node = root->root;
	while (node) {
		printf("%d ", node->key);
		node = node->nextlistnode;
	}
	printf("\n");
}

int main() {

	FILE* Hashnumber;

	fopen_s(&Hashnumber, "in.txt", "r");
	int bucketsize; rootnode** nodetableset;
	fscanf_s(Hashnumber, "%d", &bucketsize);
	nodetableset = (rootnode**)malloc(sizeof(*nodetableset) * bucketsize);
	for (int i = 0; i < bucketsize; i++)
		nodetableset[i] = createnode();
	int keynumber;
	while (!feof(Hashnumber)) {
		fscanf_s(Hashnumber, "%d", &keynumber);
		insertdivisionnode(nodetableset, keynumber, bucketsize);
	}
	fclose(Hashnumber);

	printf("Hash Table\n");
	for (int hash = 0; hash < bucketsize; hash++) {
		printf("%d: ", hash);
		printnode(nodetableset[hash]);
	}

	printf("key 검색 : ");
	scanf_s("%d", &keynumber);
	while (keynumber != -999) {
		printf("%d\n", searchnode(nodetableset, keynumber, bucketsize));
		printf("key 검색 : ");
		scanf_s("%d", &keynumber);
	}

	return 0;

}