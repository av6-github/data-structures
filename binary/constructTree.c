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

Node* buildFromPreIn(int in[], int pre[], int inStart, int inEnd, int *preIndex){
    if(inStart>inEnd) return NULL;
    int rootVal = pre[(*preIndex)++]; Node* root = createNode(rootVal);
    if(inStart==inEnd) return root;
    int inIndex;
    for(inIndex=inStart; inIndex<=inEnd; inIndex++) if(in[inIndex]==rootVal) break;
    root->left = buildFromPreIn(in, pre, inStart, inIndex-1, preIndex);
    root->right = buildFromPreIn(in, pre, inIndex+1, inEnd, preIndex);
    return root;
}

int main() {
    int inorder[]  = {4, 2, 5, 1, 3};
    int preorder[] = {1, 2, 4, 5, 3};

    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0;

    Node* root = buildFromPreIn(inorder, preorder, 0, n - 1, &preIndex);

    printf("Inorder   : ");
    inorderT(root);
    printf("\n");

    printf("Preorder  : ");
    preorderT(root);
    printf("\n");

    printf("Postorder : ");
    postorderT(root);
    printf("\n");

    return 0;
}