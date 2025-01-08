#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5

void BFS(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex, int V) {
    int visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int queue[V];
    int front = -1, rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d -> ", currentVertex);

        for (int i = 0; i < V; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    adjMatrix[0][1] = 1;
    adjMatrix[0][2] = 1;
    adjMatrix[1][3] = 1;
    adjMatrix[2][0] = 1;

    printf("BFS Traversal starting from vertex 0:\n");
    BFS(adjMatrix, 0, MAX_VERTICES);

    return 0;
}
