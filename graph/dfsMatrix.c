#include <stdio.h>

#define MAX 100

void dfs(int g[MAX][MAX], int n, int u, int vis[]) {
    vis[u] = 1;
    printf("%d ", u);

    for (int v=0; v<n; v++) {
        if (g[u][v] && !vis[v]) dfs(g, n, v, vis);
    }
}

int main() {
    int n = 5;
    int g[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,0,0},
        {0,1,0,0,1},
        {0,0,0,1,0}
    };

    int vis[MAX] = {0};

    printf("DFS from 0: ");
    dfs(g, n, 0, vis);

    return 0;
}

