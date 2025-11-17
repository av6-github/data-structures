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

void dfs(Node* adj[], int u, int vis[]) {
    vis[u] = 1;
    printf("%d ", u);

    for (Node* t = adj[u]; t; t = t->next)
        if (!vis[t->v])
            dfs(adj, t->v, vis);
}

int main() {
    int n = 5;
    Node* adj[5] = {NULL};

    addEdge(adj,0,1); addEdge(adj,1,0);
    addEdge(adj,0,2); addEdge(adj,2,0);
    addEdge(adj,1,3); addEdge(adj,3,1);
    addEdge(adj,3,4); addEdge(adj,4,3);

    int vis[100] = {0};

    printf("DFS from 0: ");
    dfs(adj, 0, vis);


    return 0;
}
