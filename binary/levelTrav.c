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

void levelOrder(Node* root){
    Node* queue[100]; int front=-1,rear=-1;
    if(!root) return;
    queue[++rear]=root;
    while(front<rear){
        Node* t=queue[++front]; 
        printf("%d ", t->data);
        if(t->left) queue[++rear]=t->left; 
        if(t->right) queue[++rear]=t->right;
    }
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

    printf("Level order traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
