#include <iostream>
using namespace std;

void Warshall(int graph[20][20], int n) 
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    int n, graph[20][20];
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    Warshall(graph, n);
    return 0;
}
/*
#include <iostream>
#include <vector>

using namespace std;

void Warshall(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<vector<int>> dist(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    vector<vector<int>> graph = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };
    Warshall(graph);
    return 0;
}
*/
