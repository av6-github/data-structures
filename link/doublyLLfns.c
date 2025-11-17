#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

Node* insertEnd(Node* head, int val) {
    Node* newNode = createNode(val);
    if (head == NULL) return newNode;

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp; // only line different from singly LL function
    return head;
}

Node *insAfterPos(Node *head, int pos, int val) {
    if (head == NULL) return head;

    Node *temp = head;
    int cnt = 1;

    while (temp != NULL && cnt < pos) {
        temp = temp->next;
        cnt++;
    }

    Node* newNode = createNode(val);
    newNode->next = temp->next;
    newNode->prev=temp;

    if (temp->next != NULL) temp->next->prev=newNode;
    temp->next=newNode;

    return head;

}

Node *sortList(Node *head) {
    if (head == NULL) return head;

    for (Node *i=head; i->next; i=i->next) {
        for (Node *j=i->next; j; j=j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    return head;

}

Node *concatenate(Node *a, Node *b) {
    if (a==NULL) return b;
    if (b==NULL) return a;

    Node *temp = a;
    while(temp->next!=NULL) temp=temp->next;

    temp->next=b;
    b->prev=temp;

    return a;
}

Node* deleteValue(Node* head,int val){ 
    Node* t=head; 
    while(t){ 
        if(t->data==val){ 
            if(t->prev) t->prev->next=t->next; 
            else head=t->next; 
            if(t->next) t->next->prev=t->prev; 
            free(t); return head; 
        } 
        t=t->next; 
    } 
    return head; 
}


void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *a = NULL, *b = NULL;

    a = insertEnd(a, 1);
    a = insertEnd(a, 2);
    a = insertEnd(a, 3);

    b = insertEnd(b, 4);
    b = insertEnd(b, 5);

    a = concatenate(a, b);

    display(a);
    return 0;
}