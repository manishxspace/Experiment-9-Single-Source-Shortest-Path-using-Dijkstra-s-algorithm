#include <iostream>
#include <climits>
using namespace std;

#define V 5

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Vertex\tShortest Distance from Source\n";

    for (int i = 0; i < V; i++) {
        cout << i << "\t";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 0, 5},
        {10, 0, 1, 0, 2},
        {0, 1, 0, 4, 0},
        {0, 0, 4, 0, 3},
        {5, 2, 0, 3, 0}
    };

    int source = 0;

    dijkstra(graph, source);

    return 0;
}