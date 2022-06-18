#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	int value;
	struct treenode* left;
	struct treenode* right;
}treenode;

void MakeBinaryTree(treenode* node, int data, int extra) {
	if (data < 10) {
		treenode* leftnode = (treenode*)malloc(sizeof(treenode));
		leftnode->value = data * extra;
		node->left = leftnode;
		MakeBinaryTree(leftnode, data * extra, extra);
	}
	printf("%d ", node->value);
	if (data < 10) {
		treenode* rightnode = (treenode*)malloc(sizeof(treenode));
		rightnode->value = data + extra;
		node->right = rightnode;
		MakeBinaryTree(rightnode, data + extra, extra);
	}
}

int main() {

	int N, X;
	printf("정수 입력 : ");
	scanf_s("%d %d", &N, &X);
	treenode* rootnode = (treenode*)malloc(sizeof(treenode));
	rootnode->value = N;
	rootnode->left = NULL; rootnode->right = NULL;
	MakeBinaryTree(rootnode, N, X);

	return 0;

}