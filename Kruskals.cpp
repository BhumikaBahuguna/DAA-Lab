#include <bits/stdc++.h>
using namespace std;
int find(int u, vector<int>& parent) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u], parent); // Path compression
}
void unionSet(int u, int v, vector<int>& parent) {
    int pu = find(u, parent), pv = find(v, parent);
    if (pu != pv)
        parent[pv] = pu;
}
vector<pair<int, pair<int, int>>> kruskals(vector<pair<int, pair<int, int>>> G, int v, int e) {
    vector<pair<int, pair<int, int>>> sol;
    sort(G.begin(), G.end());  // Sort edges by weight (first element of pair)
    vector<int> parent(v);     // Disjoint set parent array
    for (int i = 0; i < v; i++)
        parent[i] = i;         // Initialize: each node is its own parent
    for (int i = 0; i < e; i++) {
        int w = G[i].first;
        int s = G[i].second.first;
        int d = G[i].second.second;
        if (find(s, parent) != find(d, parent)) {
            sol.push_back(G[i]);         // Accept edge if no cycle
            unionSet(s, d, parent);      // Merge sets
        }
    }
    return sol;
}
int main() {
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;
    vector<pair<int, pair<int, int>>> edges;
    cout << "Enter " << e << " edges in the format: src dest weight\n";
    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edges.push_back({w, {s, d}});
    }
    auto mst = kruskals(edges, v, e);
    cout << "\nMinimum Spanning Tree edges:\n";
    int totalWeight = 0;
    for (auto edge : mst) {
    cout << "Edge: " << edge.second.first << " - " << edge.second.second;
    cout << " , Weight: " << edge.first << endl;
    totalWeight += edge.first;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}
/*

Input:
Vertices (v): 4  
Edges (e): 5

Edges (s, d, weight):
0 1 10  
0 2 6  
0 3 5  
1 3 15  
2 3 4

Output:
Edge: 2 - 3 , Weight: 4  
Edge: 0 - 3 , Weight: 5  
Edge: 0 - 2 , Weight: 10

*/
