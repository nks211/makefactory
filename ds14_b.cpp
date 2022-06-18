#define MAX_NUMBER 1000000
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int data;
    treenode* left;
    treenode* right;
}treenode;

treenode* Printnodelist[MAX_NUMBER];

bool Searchnode(treenode* root, int data) {
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data < root->data)
        return Searchnode(root->left, data);
    else
        return Searchnode(root->right, data);
}

treenode* Insertnode(treenode* root, int data) {
    if (root == NULL) {
        root = (treenode*)malloc(sizeof(treenode));
        root->data = data;
        root->left = root->right = NULL;
    }
    else {
        if (data <= root->data)
            root->left = Insertnode(root->left, data);
        else
            root->right = Insertnode(root->right, data);
    }

    return root;
}

void Levelordertraversal(treenode* root) {
    int i = 1; int j = i;
    Printnodelist[i] = root;
    while (Printnodelist[i]) {
        if (Printnodelist[i]->left)
            Printnodelist[++j] = Printnodelist[i]->left;
        if (Printnodelist[i]->right)
            Printnodelist[++j] = Printnodelist[i]->right;
        i++;
    }
    for (int k = 1; k <= j; k++)
        printf("%d ", Printnodelist[k]->data);
    printf("\n");
}

int main() {

    FILE* BSTnumber;

    fopen_s(&BSTnumber, "in.txt", "r");
    char option; int number;
    treenode* root = NULL;

    while (!feof(BSTnumber)) {
        option = fgetc(BSTnumber);
        fscanf_s(BSTnumber, "%d", &number);
        if (option == 'A') {
            printf("%c %d: ", option, number);
            if (Searchnode(root, number))
                printf("%d cannot be inserted\n", number);
            else {
                root = Insertnode(root, number);
                Levelordertraversal(root);
            }
        }
        else if(option == 'S') {
            printf("%c %d : ", option, number);
            if (Searchnode(root, number))
                printf("%d is in T\n", number);
            else
                printf("%d is not in T\n", number);
        }
    }
    fclose(BSTnumber);

	return 0;

}