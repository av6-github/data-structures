#include <stdio.h>

#define MAX 100

void bfs(int g[MAX][MAX], int n, int start) {
    int vis[MAX] = {0};
    int queue[MAX];
    int front=-1, rear=-1;

    queue[++rear] = start;
    vis[start] = 1;

    while (front < rear) {
        int u = queue[++front];
        printf("%d ", u);

        for (int v=0; v<n; v++) {
            if (g[u][v] && !vis[v]) {
                vis[v] = 1;
                queue[++rear] = v;
            }
        }
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

    printf("\nBFS from 0: ");
    bfs(g, n, 0);

    return 0;
}