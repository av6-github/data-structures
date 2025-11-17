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

int countTotal(Node* r){ 
    if(!r) return 0; 
    return 1+countTotal(r->left)+countTotal(r->right); 
}
int countLeaf(Node* r){ 
    if(!r) return 0; 
    if(!r->left && !r->right) return 1; 
    return countLeaf(r->left)+countLeaf(r->right); 
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

    int total = countTotal(root);
    int leaf  = countLeaf(root);

    printf("Total nodes: %d\n", total);
    printf("Leaf nodes : %d\n", leaf);

    return 0;
}
