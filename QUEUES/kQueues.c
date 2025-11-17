#include <stdio.h>

#define MAXN 100   
#define MAXK 100  

int kQueue[MAXK][MAXN]; 
int frontK[MAXK], rearK[MAXK];

void enqueue(int qn, int x) {
    if (rearK[qn] == MAXN - 1) {
        printf("Queue %d overflow\n", qn);
        return;
    }
    if (frontK[qn] == -1) frontK[qn] = 0;

    kQueue[qn][++rearK[qn]] = x;
    printf("Enqueued %d in queue %d\n", x, qn);
}

void dequeue(int qn) {
    if (frontK[qn] == -1 || frontK[qn] > rearK[qn]) {
        printf("Queue %d is empty\n", qn);
        return;
    }

    int x = kQueue[qn][frontK[qn]++];
    printf("Dequeued %d from queue %d\n", x, qn);

    if (frontK[qn] > rearK[qn]) {
        frontK[qn] = rearK[qn] = -1; 
    }
}

void displayq(int qn) {
    if (frontK[qn] == -1) {
        printf("Queue %d is empty\n", qn);
        return;
    }

    printf("Queue %d: ", qn);
    for (int i = frontK[qn]; i <= rearK[qn]; i++) {
        printf("%d ", kQueue[qn][i]);
    }
    printf("\n");
}

void displayAll(int K) {
    for (int i = 0; i < K; i++) {
        displayq(i);
    }
}

int main() {
    int K;
    printf("Enter number of queues: ");
    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        frontK[i] = rearK[i] = -1;
    }

    int choice, qn, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display One Queue\n4. Display All\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter queue number (0-%d): ", K-1);
            scanf("%d", &qn);
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(qn, x);
        }
        else if (choice == 2) {
            printf("Enter queue number (0-%d): ", K-1);
            scanf("%d", &qn);
            dequeue(qn);
        }
        else if (choice == 3) {
            printf("Enter queue number (0-%d): ", K-1);
            scanf("%d", &qn);
            displayq(qn);
        }
        else if (choice == 4) {
            displayAll(K);
        }
        else {
            break;
        }
    }

    return 0;
}
