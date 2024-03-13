#include <iostream>
using namespace std;

void warshall(int a[20][20], int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = (a[i][j] || a[i][k] && a[k][j]);
}

int main() {
    int n, a[20][20];
    cout << "Enter number of nodes in the graph: ";
    cin >> n;
    cout << "Enter the adjacency matrix for the graph: \n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    warshall(a, n);
    cout << "\nThe path matrix is: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] <<"\t";
        cout << endl;
    }
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
