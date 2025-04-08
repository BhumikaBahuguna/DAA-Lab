#include <bits/stdc++.h>
using namespace std;
// Find function with path compression
int find(int u, int* parent) {
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u], parent); // Path compression
}
// Union function
void unionSet(int u, int v, int* parent) {
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu != pv)
        parent[pv] = pu; // Merge sets
}
int main() {
    int v;
    cout << "Enter number of nodes: ";
    cin >> v;
    int parent[v];
    for (int i = 0; i < v; i++)
        parent[i] = i; // Initially, every node is in its own set
    int unions;
    cout << "Enter number of union operations: ";
    cin >> unions;
    cout << "Enter " << unions << " pairs to union:\n";
    for (int i = 0; i < unions; i++) {
        int u, vtx;
        cin >> u >> vtx;
        unionSet(u, vtx, parent);
    }
    int queries;
    cout << "Enter number of find queries: ";
    cin >> queries;
    cout << "Enter " << queries << " nodes to find their set:\n";
    for (int i = 0; i < queries; i++) {
        int node;
        cin >> node;
        cout << "Set of node " << node << ": " << find(node, parent) << endl;
    }
    return 0;
}
/*
OUTPUT FORMAT :
Input:
Enter number of nodes: 6
Enter number of union operations: 4
Enter 4 pairs to union:
0 1
1 2
3 4
4 5
Enter number of find queries: 6
Enter 6 nodes to find their set:
0
1
2
3
4
5
Output:
Set of node 0: 0
Set of node 1: 0
Set of node 2: 0
Set of node 3: 3
Set of node 4: 3
Set of node 5: 3
*/
