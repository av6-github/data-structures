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