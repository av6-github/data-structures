#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int *top;  
    int segSize; 
    int k;      
} kStacks;

kStacks* createKStacks(int n, int k) {
    kStacks* ks = (kStacks*)malloc(sizeof(kStacks));
    ks->segSize = n / k;
    ks->k = k;

    ks->arr = (int*)malloc(n * sizeof(int));
    ks->top = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++)
        ks->top[i] = i * ks->segSize - 1;

    return ks;
}

void push(kStacks* ks, int x, int i) {
    if (ks->top[i] != ks->segSize - 1) {
        int end = (i + 1) * ks->segSize - 1;
        ks->top[i]++;
        ks->arr[ks->top[i]] = x;
    } else printf("\nStack Overflow");
}

int pop(kStacks* ks, int i) {
    int start = i * ks->segSize;

    if (ks->top[i] < start) {
        printf("Stack %d underflow\n", i);
        return -1;
    }

    int val = ks->arr[ks->top[i]];
    ks->top[i]--;
    return val;
}

int main() {
    int n, k;

    printf("Enter total array size: ");
    scanf("%d", &n);

    printf("Enter number of stacks: ");
    scanf("%d", &k);

    kStacks* ks = createKStacks(n, k);

    int choice, stackNum, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Display All Stacks\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter stack number (0-%d): ", k-1);
            scanf("%d", &stackNum);

            printf("Enter value to push: ");
            scanf("%d", &value);

            push(ks, value, stackNum);
        }

        else if (choice == 2) {
            printf("Enter stack number (0-%d): ", k-1);
            scanf("%d", &stackNum);

            int popped = pop(ks, stackNum);
            if (popped != -1)
                printf("Popped from stack %d: %d\n", stackNum, popped);
        }

        else if (choice == 3) {
            printf("Enter stack number (0-%d): ", k-1);
            scanf("%d", &stackNum);

            int start = stackNum * ks->segSize;
            int end   = (stackNum + 1) * ks->segSize - 1;

            printf("Stack %d: ", stackNum);
            for (int i = start; i <= ks->top[stackNum]; i++)
                printf("%d ", ks->arr[i]);
            printf("\n");
        }

        else if (choice == 4) {
            for (int s = 0; s < k; s++) {
                int start = s * ks->segSize;
                printf("Stack %d: ", s);
                for (int i = start; i <= ks->top[s]; i++)
                    printf("%d ", ks->arr[i]);
                printf("\n");
            }
        }

        else break;
    }

    return 0;
}
