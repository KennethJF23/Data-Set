#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999999

// Structure to represent a disjoint set
struct DisjointSet {
    int parent[MAX];
    int rank[MAX];
};

// Structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to initialize disjoint set
void makeSet(struct DisjointSet *set, int n) {
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
}

// Function to find the representative of the set containing x
int findSet(struct DisjointSet *set, int x) {
    if (set->parent[x] != x)
        set->parent[x] = findSet(set, set->parent[x]); // Path compression
    return set->parent[x];
}

// Function to unite two sets
void unionSets(struct DisjointSet *set, int x, int y) {
    int rootX = findSet(set, x);
    int rootY = findSet(set, y);
    if (rootX != rootY) {
        if (set->rank[rootX] > set->rank[rootY]) {
            set->parent[rootY] = rootX;
        } else if (set->rank[rootX] < set->rank[rootY]) {
            set->parent[rootX] = rootY;
        } else {
            set->parent[rootY] = rootX;
            set->rank[rootX]++;
        }
    }
}

// Function to compare two edges for sorting
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Kruskal's algorithm to find the Minimum Spanning Tree
void kruskal(struct Edge edges[], int n, int e) {
    struct DisjointSet set;
    makeSet(&set, n);
    
    qsort(edges, e, sizeof(struct Edge), compareEdges);
    
    int mstWeight = 0;
    printf("\nKruskal's Algorithm - Edges in MST (source   final   weight):\n");
    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        
        if (findSet(&set, u) != findSet(&set, v)) {
            printf("%d -------- %d    %d\n", u, v, weight);
            mstWeight += weight;
            unionSets(&set, u, v);
        }
    }
    printf("Total weight of MST (Kruskal's): %d\n", mstWeight);
}

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's algorithm to find MST
void prim(int edges[MAX][MAX], int n) {
    int parent[n]; // Array to store the MST
    int key[n];    // Key values used to pick minimum weight edge
    int mstSet[n]; // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = 0;
        parent[i] = -1;
    }
    
    // Start with the first vertex
    key[0] = 0;
    
    int mstWeight = 0; // Variable to store the total weight of MST
    
    // Run Prim’s algorithm for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, n);
        
        // Add the picked vertex to the MST Set
        mstSet[u] = 1;
        
        // Update key and parent values of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (edges[u][v] && mstSet[v] == 0 && edges[u][v] < key[v]) {
                key[v] = edges[u][v];
                parent[v] = u;
            }
        }

        // Step-by-step output
        printf("\nStep %d:\n", count + 1);
        printf("    ");
        for (int i = 0; i < n; i++) {
            printf("%d\t", i);  // Print vertex labels (0, 1, 2, ...)
        }
        printf("\n");

        printf("d   ");
        for (int i = 0; i < n; i++) {
            if (key[i] == INF) {
                printf("∞\t");  // Print ∞ if the vertex is not yet added to MST
            } else {
                printf("%d\t", key[i]);
            }
        }
        printf("\n");

        printf("pi  ");
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                printf("N\t");  // Print N if no parent exists
            } else {
                printf("%d\t", parent[i]);
            }
        }
        printf("\n");

        // Add the key value to the total MST weight
        mstWeight += key[u];
    }

    // Output the MST edges and their weights
    printf("\nEdges in MST:\n");
    int totalCost = 0;
    for (int i = 1; i < n; i++) {
        printf("%d - %d \t%d \n", parent[i], i, edges[i][parent[i]]);
        totalCost += edges[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}


int main() {
    int n, e;
    printf("NAME:KENNETH FERNANDES ROLL.NO:40 STD:S.E CMPN-A\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);

    struct Edge edges[e];
    int adjMatrix[MAX][MAX] = {0};
    
    printf("\nEnter the edges (source final weight) for Kruskal's Algorithm:\n");
    for (int i = 0; i < e; i++) {
        printf("Enter edge %d (source final weight): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    printf("\nEnter the edges (source final weight) for Prim's Algorithm:\n");
    for (int i = 0; i < e; i++) {
        int u, v, weight;
        printf("Enter edge %d (source final weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    kruskal(edges, n, e);
    prim(adjMatrix, n);

    return 0;
}
