#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *push(Node *top, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = top;
    return newNode;
}

Node *pop(Node *top) {
    if (top == NULL) return NULL;
    Node *temp = top->next;
    free(top);
    return temp;
}

int peek(Node *top) {
    return top->data;
}

void printStack(Node *top) {
    Node *temp = top;
    while(temp) {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    Node *top = NULL;
    top = push(top, 5);
    top = push(top, 10);
    top = push(top, 15);
    printStack(top);
    top = pop(top);
    printStack(top);
    printf("%d", peek(top));
    return 0;
}