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

void preorderT(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderT(root->left);
    preorderT(root->right);
}

void postorderT(Node *root) {
    if (root == NULL) return;
    postorderT(root->left);
    postorderT(root->right);
    printf("%d ", root->data);
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

int countTotal(Node* r){ 
    if(!r) return 0; 
    return 1+countTotal(r->left)+countTotal(r->right); 
}
int countLeaf(Node* r){ 
    if(!r) return 0; 
    if(!r->left && !r->right) return 1; 
    return countLeaf(r->left)+countLeaf(r->right); 
}

/* mirror */
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

/* build tree from inorder & preorder (standard) */
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

// iterative post order

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