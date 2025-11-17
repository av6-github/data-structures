#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a=*b;
    *b=t;
}

void minHeapify(int a[], int n, int i) {
    int smallest=i; 
    int l = 2*i+1;
    int r = 2*i+2;
    if (l<n && a[l] < a[smallest]) smallest=l;
    if (r<n && a[r] < a[smallest]) smallest=r;
    if (smallest!=i) {
        swap(&a[i], &a[smallest]);
        minHeapify(a, n, smallest);
    }
}

int extractMin(int a[], int *n) {
    if (*n<=0) return -1;
    int root = a[0];
    a[0] = a[*n-1];
    (*n)--;
    minHeapify(a, *n, 0);
    return root;
}

void heapSortMin(int a[], int n) {
    for (int i=n/2 - 1; i>=0; i--) minHeapify(a, n, i);

    for (int i=n-1; i>0; i--) {
        swap(&a[0], &a[i]);
        minHeapify(a, i, 0);
    }
}


int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    heapSortMin(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    int min = extractMin(a, &n);
    printf("extracted %d\n", min);

    heapSortMin(a, n);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}