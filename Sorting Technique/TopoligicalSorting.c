#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// Structure to represent an adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_NODES];
    int inDegree[MAX_NODES];
};

// Create a new adjacency list node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }
    return graph;
}

// Add a directed edge from src to dest (src -> dest)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    
    // Increment in-degree of the destination node
    graph->inDegree[dest]++;
}

// Kahn's Algorithm (BFS) for Topological Sorting
void topologicalSort(struct Graph* graph) {
    int queue[MAX_NODES];
    int front = 0, rear = 0;
    int order[MAX_NODES];
    int index = 0;

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < graph->numVertices; i++) {
        if (graph->inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process nodes
    while (front < rear) {
        int u = queue[front++];
        order[index++] = u;

        // Decrease in-degree for all neighbor nodes
        struct Node* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex;
            graph->inDegree[v]--;
            
            // If in-degree becomes 0, add to queue
            if (graph->inDegree[v] == 0) {
                queue[rear++] = v;
            }
            temp = temp->next;
        }
    }

    // Check for cycles
    if (index != graph->numVertices) {
        printf("Error: The graph contains a cycle. Topological sort impossible.\n");
        return;
    }

    // Print the sorted order
    printf("Topological Sort: ");
    for (int i = 0; i < index; i++) {
        printf("%d ", order[i]);
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    // Example Graph Edges
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);

    return 0;
}
