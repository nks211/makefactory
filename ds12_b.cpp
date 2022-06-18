#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	int value;
	struct treenode* left;
	struct treenode* right;
}treenode;

void printleafnode(treenode* node, int data, int extra) {
	if (data < 10) {
		treenode* leftnode = (treenode*)malloc(sizeof(treenode));
		leftnode->value = data * extra;
		node->left = leftnode;
		printleafnode(leftnode, data * extra, extra);
	}
	if (data >= 10)
		printf("%d ", node->value);
	if (data < 10) {
		treenode* rightnode = (treenode*)malloc(sizeof(treenode));
		rightnode->value = data + extra;
		node->right = rightnode;
		printleafnode(rightnode, data + extra, extra);
	}
}

int main() {

	int n, x;
	printf("정수 입력 : ");
	scanf_s("%d %d", &n, &x);
	treenode* Rootnode = (treenode*)malloc(sizeof(treenode));
	Rootnode->value = n;
	Rootnode->left = NULL; Rootnode->right = NULL;
	printleafnode(Rootnode, n, x);

	return 0;

}