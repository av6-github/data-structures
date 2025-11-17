#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node* next;
} Node;

void addEdge(Node* adj[], int u, int v) {
    Node* n = malloc(sizeof(Node));
    n->v = v;
    n->next = adj[u];
    adj[u] = n;
}

void bfs(Node* adj[], int n, int start) {
    int vis[100] = {0}, q[100], f=0, r=0;

    q[r++] = start;
    vis[start] = 1;

    while (f < r) {
        int u = q[f++];
        printf("%d ", u);

        for (Node* t = adj[u]; t; t = t->next) {
            if (!vis[t->v]) {
                vis[t->v] = 1;
                q[r++] = t->v;
            }
        }
    }
}

int main() {
    int n = 5;
    Node* adj[5] = {NULL};

    addEdge(adj,0,1); addEdge(adj,1,0);
    addEdge(adj,0,2); addEdge(adj,2,0);
    addEdge(adj,1,3); addEdge(adj,3,1);
    addEdge(adj,3,4); addEdge(adj,4,3);

    int vis[100] = {0};

    printf("\nBFS from 0: ");
    bfs(adj, n, 0);

    return 0;
}
