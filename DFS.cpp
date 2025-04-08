#include <bits/stdc++.h>
using namespace std;
void dfsutils(vector<int> G[], vector<int>& visited, int src) {
    visited[src] = 1;
    for (auto i : G[src]) {
        if (visited[i] == 0)
            dfsutils(G, visited, i);
    }
    cout << src << " ";
    visited[src] = 2;
}
void DFS(vector<int> G[], int v) {
    vector<int> visited(v, 0);
    for (int i = 0; i < v; i++) {
        if (visited[i] == 0) {
            dfsutils(G, visited, i);
        }
    }
}
int main() {
    int v, e, s, d;
    cin >> v >> e;
    vector<int> G[v];
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        G[s].push_back(d);
        G[d].push_back(s); 
    }
    DFS(G, v);
}
