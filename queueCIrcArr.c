#include <stdio.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear, size;
} Queue;

void init(Queue *q){
    q->front=q->rear=-1;
    q->size=0;
}

int isEmpty(Queue *q){ return q->size==0; }
int isFull(Queue *q){ return q->size==MAX; }

void enqueue(Queue *q, int x){
    if(isFull(q)) return;
    if(isEmpty(q)) q->front=0;
    q->rear = (q->rear+1)%MAX;
    q->arr[q->rear]=x;
    q->size++;
}

int dequeue(Queue *q){
    if(isEmpty(q)) return -1;
    int x=q->arr[q->front];
    q->front=(q->front+1)%MAX;
    q->size--;
    if(q->size==0) q->front=q->rear=-1;
    return x;
}

int front(Queue *q){ return q->arr[q->front]; }
int rear(Queue *q){ return q->arr[q->rear]; }

int main(){
    Queue q; init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    printf("%d ", dequeue(&q));
    printf("%d ", front(&q));
    return 0;
}
