#include <bits/stdc++.h>
using namespace std;

#define V 6 // Number of vertices
#define INF INT_MAX

void bellmanFord(int graph[V][V], int src) {
    vector<int> value(V, INF); // Keeps shortest path values to each vertex from source
    value[src] = 0; // Start node has value=0

    // Relax all edges (V-1) times
    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != 99 && value[u] != INF && value[u] + graph[u][v] < value[v]) {
                    value[v] = value[u] + graph[u][v];
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != 99 && value[u] != INF && value[u] + graph[u][v] < value[v]) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    // Print Shortest Path Values
    cout << "Value array is" << endl;
    for (int i = 0; i < V; i++) {
        cout << value[i] << " ";
    }
    cout << endl;
}

int main() {
    int graph[V][V] = { {0, 1, 4, 99, 99, 99},
                        {1, 0, 4, 2, 7, 99},
                        {4, 4, 0, 3, 5, 99},
                        {99, 2, 3, 0, 4, 6},
                        {99, 7, 5, 4, 0, 7},
                        {99, 99, 99, 6, 7, 0} };

    bellmanFord(graph, 0);	
    return 0;
}
