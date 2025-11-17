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

Node* reverse(Node* head) {
    Node *prev=NULL, *cur=head, *next=NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node *addLists(Node *a, Node *b) {
    a = reverse(a);
    b = reverse(b);

    Node *res = NULL;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;
        if (a) {
            sum += a->data;
            a=a->next;
        }
        if (b) {
            sum += b->data;
            b=b->next;
        }

        carry = sum / 10;
        res = insertEnd(res, sum % 10);
    }

    return reverse(res);
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

    Node *a = NULL, *b=NULL;
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

    while (true) {
        scanf("%d", &n);
        if (n == -1) break;
        Node *newNode = createNode(n);
        if (b == NULL) b = newNode;
        else {
            Node *temp = b;
            while(temp -> next != NULL) temp = temp->next;
            temp->next=newNode;
        }
    }

    Node *res = addLists(a, b);
    printList(res);

    return 0;
}