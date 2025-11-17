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

Node* swapPairs(Node* head){
    if(!head || !head->next) return head;
    Node* prev=NULL; 
    Node* curr=head;

    head=head->next;
    while(curr && curr->next){
        Node* nxtPair = curr->next->next;
        Node* second = curr->next;

        second->next=curr; 
        curr->next=nxtPair;
        if(prev) prev->next=second;

        prev=curr; 
        curr=nxtPair;
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

    Node *res = swapPairs1(a);
    printList(res);

    return 0;
}