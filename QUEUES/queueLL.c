#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

Node* createNode(int x) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}

void enqueue(Queue* q, int x) {
    Node* n = createNode(x);

    if (q->rear == NULL) {
        q->front = q->rear = n;
        return;
    }

    q->rear->next = n;
    q->rear = n;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue underflow\n");
        return -1;
    }

    Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void display(Queue* q) {
    Node* t = q->front;
    while (t) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40);
    display(q);

    return 0;
}
