#include <bits/stdc++.h>
using namespace std;
void dijkstra(vector<vector<pair<int, int>>> &g, int v) {
    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(v, INT_MAX);
    dist[0] = 0; // Assuming source is 0
    pq.push({0, 0}); // {distance, vertex}
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int v_adj = g[u][i].first;
            int weight = g[u][i].second;
            if (dist[u] + weight < dist[v_adj]) {
                dist[v_adj] = dist[u] + weight;
                pq.push({dist[v_adj], v_adj});
            }
        }
    }
    cout << "Shortest distances from source (0):\n";
    for (int i = 0; i < v; i++) {
        cout << "0 -> " << i << " = " << dist[i] << endl;
    }
}
int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> g(v);  // Adjacency list
    auto addedge = [&](int u, int v, int w) {
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    };
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    dijkstra(g, v);
    return 0;
}
/*
INPUT:
5 7
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

OUTPUT:
0 -> 0 = 0
0 -> 1 = 2
0 -> 2 = 5
0 -> 3 = 6
0 -> 4 = 7

*/
