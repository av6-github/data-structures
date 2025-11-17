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

void inorderT(Node *root) {
    if (root == NULL) return;
    inorderT(root->left);
    printf("%d ", root->data);
    inorderT(root->right);
}

int height(Node* root) {
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
        return lh + 1;
    else
        return rh + 1;
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

    printf("Inorder traversal: ");
    inorderT(root);

    int h = height(root);
    printf("\nHeight of tree: %d\n", h);

    return 0;
}
