#include <bits/stdc++.h>
using namespace std;
void bellmanFord(int V, vector<vector<pair<int, int>>> &g, int source) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[source] = 0;
    bool negativeCycle = false;
    // Run V iterations (0 to V-1)
    for (int i = 0; i < V; i++) {
        bool updated = false;
        for (int u = 0; u < V; u++) {
            for (auto it = g[u].begin(); it != g[u].end(); ++it) {
                int v = it->first;
                int wt = it->second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    updated = true;
                }
            }
        }
        // If no updates, we can break early
        if (!updated) break;
        // If still updating on V-th iteration, negative cycle exists
        if (i == V - 1 && updated) {
            negativeCycle = true;
        }
    }
    if (negativeCycle) {
        cout << "Graph contains a negative weight cycle\n";
        return;
    }
    // Print shortest distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << " : INF\n";
        else
            cout << i << " : " << dist[i] << "\n";
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> g(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w}); // Directed graph
    }
    int source;
    cin >> source;
    bellmanFord(V, g, source);
    return 0;
}

