#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* createNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

Node* createRec(int n) {
    if (n == 0) return NULL;

    int x;
    scanf("%d", &x);

    Node* head = createNode(x);
    head->next = createRec(n - 1);   // recursive call

    return head;
}

void displayRec(Node* head) {
    if (head == NULL) return;
    printf("%d ", head->data);
    displayRec(head->next);          // recursive step
}

int lengthRec(Node* head) {
    if (head == NULL) return 0;
    return 1 + lengthRec(head->next);
}

Node* reverseRec(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* rest = reverseRec(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = createRec(n);

    printf("List: ");
    displayRec(head);
    printf("\n");

    printf("Length: %d\n", lengthRec(head));

    head = reverseRec(head);

    printf("Reversed: ");
    displayRec(head);
    printf("\n");

    return 0;
}
