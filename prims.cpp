#include <bits/stdc++.h>
using namespace std;
// Prim's Algorithm
void prims(vector<vector<pair<int, int>>> &g, int v) {
    typedef pair<int, int> pii;
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
    vector<int> key(v, INT_MAX);       // Min weight to reach each vertex
    vector<bool> inMST(v, false);      // Tracks if vertex is in MST
    vector<int> parent(v, -1);         // Stores parent of each vertex
    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        for (int i = 0; i < g[u].size(); i++) {
            int v_adj = g[u][i].first;
            int weight = g[u][i].second;
            if (!inMST[v_adj] && weight < key[v_adj]) {
                key[v_adj] = weight;
                parent[v_adj] = u;
                pq.push({weight, v_adj});
            }
        }
    }
    cout << "Edges in MST:\n";
    for (int i = 1; i < v; i++) {
        cout << parent[i] << " - " << i << endl;
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
    prims(g, v);
    return 0;
}
/*for (auto [v_adj, weight] : g[u]) {
            if (!inMST[v_adj] && weight < key[v_adj]) {
                key[v_adj] = weight;
                parent[v_adj] = u;
                pq.push({weight, v_adj});
            }
        }
            */
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
Edges in MST:
0 - 1
1 - 2
0 - 3
1 - 4

*/
