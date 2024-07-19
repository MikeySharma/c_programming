//Graph DFS Traversal (Depth First Search)
#include <stdio.h>

 int visited[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    int adj[8][8] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0, 1, 0}
    };

void DFS(int i){
    visited[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < 8; j++)
    {
        if(adj[i][j] && !visited[j]){
            DFS(j);
        }
    }
}
int main() {
   
    DFS(0);
    return 0;
}