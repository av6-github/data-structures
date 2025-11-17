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

void mirror(Node* r){ 
    if(!r) return; 
    Node* t=r->left; 
    r->left=r->right; 
    r->right=t; 
    mirror(r->left); 
    mirror(r->right); 
}

bool isEqual(Node *r1, Node *r2) {
    if (!r1 && !r2) return true; // both empty
    if (!r1 || !r2) return false; // only one empty

    return (
        r1->data==r2->data && 
        isEqual(r1->left, r2->left) && 
        isEqual(r1->right, r2->right)
    );
}

int main() {
    Node *root1 = NULL;
    Node *root2 = NULL;
    int n, x;

    printf("Enter number of nodes for Tree 1: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root1 = insert(root1, x);
    }

    printf("\nEnter number of nodes for Tree 2: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root2 = insert(root2, x);
    }

    if (isEqual(root1, root2))
        printf("\nTrees are EQUAL\n");
    else
        printf("\nTrees are NOT equal\n");

    mirror(root1);

    printf("\nAfter mirroring Tree 1, checking equality again...\n");

    if (isEqual(root1, root2))
        printf("Trees are equal now\n");
    else
        printf("Trees are still not equal\n");

    return 0;
}
