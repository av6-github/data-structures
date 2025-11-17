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

Node *revList(Node *head) {
    Node *prev = NULL, *curr = head, *next = NULL;
    while(curr != NULL) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPal(Node *head) {
    if (head == NULL || head->next == NULL) return true;

    Node *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *secondHalf = revList(slow->next);
    Node *h1 = head;
    Node *h2 = secondHalf;

    while(h2 != NULL) {
        if (h1 -> data != h2 -> data) return false;
        h1=h1->next;
        h2=h2->next;
    }

    return true;
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

    printList(head);
    if (isPal(head)) printf("above list is a palindrome\n");
    else printf("above list is not a palindrome\n");
    
    return 0;
}


