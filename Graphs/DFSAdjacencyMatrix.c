#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

void DFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex, int visited[], int V) {
    visited[startVertex] = 1;
    printf("%d -> ", startVertex);

    for (int i = 0; i < V; i++) {
        if (adjMatrix[startVertex][i] == 1 && !visited[i]) {
            DFS(adjMatrix, i, visited, V);
        }
    }
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[2][0] = 1;

    int visited[MAX_VERTICES] = {0};

    printf("DFS Traversal starting from vertex 0:\n");
    DFS(adjMatrix, 0, visited, MAX_VERTICES);

    return 0;
}
