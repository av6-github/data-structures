#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node *insert(Node *root, int data) {
    if (root==NULL) return createNode(data);
    if (data < root->data) root->left=insert(root->left, data);
    else if (data > root->data) root->right=insert(root->right, data);
    return root;
}

void descending(Node *root) {
    if (root == NULL) return;
    descending(root->right);
    printf("%d ", root->data);
    descending(root->left);
}

int main() {
    Node *root = NULL;
    int n, x;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("BST in descending order:\n");
    descending(root);

    printf("\n");
    return 0;
}
