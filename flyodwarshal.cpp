#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>& dist, int v) {
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
void printDistanceMatrix(const vector<vector<int>>& dist) {
    int v = dist.size();
    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    vector<vector<int>> dist(v, vector<int>(v));
    cout << "Enter the adjacency matrix (use -1 for no direct edge):\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            int weight;
            cin >> weight;

            if (weight == -1 && i != j)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = weight;
        }
    }
    floydWarshall(dist, v);
    printDistanceMatrix(dist);
    return 0;
}
