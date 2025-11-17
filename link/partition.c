#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int x) {
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

Node* insertEnd(Node *head, int x) {
    Node *n = createNode(x);
    if (!head) return n;
    Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
    return head;
}

Node* partition(Node *head, int x) {
    Node *lessH=NULL,*lessT=NULL;
    Node *equalH=NULL,*equalT=NULL;
    Node *greaterH=NULL,*greaterT=NULL;

    Node *t = head;

    while (t) {
        if (t->data < x) {
            if (!lessH) lessH=lessT=createNode(t->data);
            else lessT = lessT->next = createNode(t->data);
        }
        else if (t->data == x) {
            if (!equalH) equalH=equalT=createNode(t->data);
            else equalT = equalT->next = createNode(t->data);
        }
        else {
            if (!greaterH) greaterH=greaterT=createNode(t->data);
            else greaterT = greaterT->next = createNode(t->data);
        }
        t = t->next;
    }

    if (!lessH) {
        if (!equalH) return greaterH;
        equalT->next = greaterH;
        return equalH;
    }

    if (!equalH) {
        lessT->next = greaterH;
        return lessH;
    }

    lessT->next = equalH;
    equalT->next = greaterH;
    return lessH;
}

void display(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 5);
    head = insertEnd(head, 3);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insertEnd(head, 2);

    int x = 3;
    
    printf("Original: ");
    display(head);

    head = partition(head, x);

    printf("Partitioned: ");
    display(head);

    return 0;
}
