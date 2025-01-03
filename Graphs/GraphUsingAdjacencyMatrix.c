#include <stdio.h>
#define MAX_VERTICES 5

void addEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;  // For undirected graph
}

void printAdjMatrix(int adjMatrix[MAX_VERTICES][MAX_VERTICES]) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    // Adding edges
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);

    // Print the adjacency matrix
    printf("Adjacency Matrix Representation:\n");
    printAdjMatrix(adjMatrix);

    return 0;
}
