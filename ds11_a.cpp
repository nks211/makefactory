#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct rootnode {
	node* root;
}roornode;

rootnode* createrootnode() {
	rootnode* headnode;
	headnode = (rootnode*)malloc(sizeof(rootnode));
	headnode->root = NULL;
	return headnode;
}

void connectchildnode(rootnode* root, node* parentnode, int childnumber) {
	node* newnode; node* firstnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->data = childnumber;
	newnode->left = NULL; newnode->right = NULL;
	if (root->root == NULL) {
		root->root = newnode;
		return;
	}
	else {
		firstnode = parentnode;
		if (firstnode->left) {
			firstnode->right = newnode;
		}
		else {
			firstnode->left = newnode;
		}
	}
}

void postorder(node* nodenumber) {
	if (nodenumber->left)
		postorder(nodenumber->left);
	if (nodenumber->right)
		postorder(nodenumber->right);
	printf("%d ", nodenumber->data);
}

int main() {

	rootnode* Root = createrootnode();
	connectchildnode(Root, NULL, 4);
	node* rootnode = Root->root;
	connectchildnode(Root, rootnode, 2);
	connectchildnode(Root, rootnode, 5);
	connectchildnode(Root, rootnode->left, 1);
	connectchildnode(Root, rootnode->left, 3);
	connectchildnode(Root, rootnode->right, 6);
	
	postorder(rootnode);

	return 0;

}