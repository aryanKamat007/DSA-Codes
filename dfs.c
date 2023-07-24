#include <stdio.h>

#define MAX_VERTICES 100

typedef struct {
  int visited;
  int adj[MAX_VERTICES];
} Graph;

void dfs(Graph *graph, int vertex) {
  graph->visited[vertex] = 1;
  printf("%d ", vertex);
  for (int i = 0; i < MAX_VERTICES; i++) {
    if (graph->adj[vertex][i] && !graph->visited[i]) {
      dfs(graph, i);
    }
  }
}

int main() {
  Graph graph;
  int vertices, edges, u, v;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < vertices; i++) {
    graph.visited[i] = 0;
    for (int j = 0; j < MAX_VERTICES; j++) {
      graph.adj[i][j] = 0;
    }
  }

  for (int i = 0; i < edges; i++) {
    printf("Enter the two vertices connected by an edge: ");
    scanf("%d %d", &u, &v);
    graph.adj[u][v] = 1;
    graph.adj[v][u] = 1;
  }

  printf("The connected components are: ");
  for (int i = 0; i < vertices; i++) {
    if (!graph.visited[i]) {
      dfs(&graph, i);
      printf("\n");
    }
  }

  return 0;
}


