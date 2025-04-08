#include <bits/stdc++.h>
using namespace std;
void BFS(vector<int> G[], int v, int src) {
    queue<int> q;
    vector<bool> visited(v, false);
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (auto i : G[vertex]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
        cout << vertex << " ";
    }
}
int main() {
    int v, e, s, d;
    cout << "Enter number of vertices and edges:\n";
    cin >> v >> e;
    vector<int> G[v];
    cout << "Enter each edge (source destination):\n";
    for (int i = 0; i < e; i++) {
        cin >> s >> d;
        G[s].push_back(d);
        G[d].push_back(s);
    }
    int src;
    cout << "Enter starting node for BFS:\n";
    cin >> src;
    cout << "BFS traversal:\n";
    BFS(G, v, src);
}
