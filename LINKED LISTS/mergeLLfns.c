#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node* insertEnd(Node* head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

int isEqual(Node* a, Node* b) {
    while (a != NULL && b != NULL) {
        if (a->data != b->data)
            return 0;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

Node* copyList(Node* head) {
    if (head == NULL) return NULL;

    Node* newNodePtr = createNode(head->data);
    newNodePtr->next = copyList(head->next);

    return newNodePtr;
}


void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp -> next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {

    Node *a = NULL;
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == -1) break;
        Node *newNode = createNode(n);
        if (a == NULL) a = newNode;
        else {
            Node *temp = a;
            while(temp -> next != NULL) temp = temp->next;
            temp->next=newNode;
        }
    }

    Node *res = swapPairs(a);
    printList(res);

    return 0;
}