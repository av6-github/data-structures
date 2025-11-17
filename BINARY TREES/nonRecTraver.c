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

void inorderIter(Node* root){
    Node* stack[100]; int top=-1; Node* cur=root;
    while(cur || top!=-1){
        while(cur){ 
            stack[++top]=cur; 
            cur=cur->left; 
        }
        cur=stack[top--];
        printf("%d ", cur->data);
        cur=cur->right;
    }
}

void preorderIter(Node* root){
    Node* stack[100]; int top=-1; Node* cur=root;
    while(cur || top!=-1){
        while(cur){ 
            printf("%d ", cur->data); 
            stack[++top]=cur;
            cur=cur->left;   
        }

        cur=stack[top--];
        cur=cur->right;
    }
}

void postorderIter(Node* root) {
    Node* stack[100];
    int top = -1;
    Node* cur = root;
    Node* prev = NULL;

    while (cur || top != -1) {

        while (cur) {
            stack[++top] = cur;
            cur = cur->left;
        }

        Node* peek = stack[top];

        if (peek->right == NULL || peek->right == prev) {
            printf("%d ", peek->data);
            top--;
            prev = peek;
        }
        else {
            cur = peek->right;
        }
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

    printf("Inorder (iterative): ");
    inorderIter(root);

    printf("\nPreorder (iterative): ");
    preorderIter(root);

    printf("\nPostorder (iterative): ");
    postorderIter(root);

    printf("\n");
    return 0;
}

