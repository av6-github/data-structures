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

Node *rotate(Node *head, int k) {
    if(head == NULL || k==0) return head;

    int len=1; 
    Node* tail=head;
    while(tail->next){ tail=tail->next; len++; }

    k%=len;
    if(k==0) return head;
    
    tail->next=head;
    int steps = len - k;
    
    Node* newTail=head;
    for(int i=1;i<steps;i++) newTail=newTail->next;

    Node* newHead=newTail->next; 
    newTail->next=NULL; 
    return newHead;

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

    printList(a);
    Node *res = rotate(a, 2);
    printList(res);

    return 0;
}