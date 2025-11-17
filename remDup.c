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

Node *removeDup(Node *head) {
    if (head==NULL || head->next==NULL) return head;

    Node *current = head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node *dup = current->next;
            current->next=dup->next;
            free(dup);
        } else current = current -> next;
    }

    return head;
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

    Node *head = NULL;
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == -1) break;
        Node *newNode = createNode(n);
        if (head == NULL) head = newNode;
        else {
            Node *temp = head;
            while(temp -> next != NULL) temp = temp->next;
            temp->next=newNode;
        }
    }

    printList(removeDup(head));

    return 0;
}