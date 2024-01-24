#include <iostream>
#include <vector>

using namespace std;

void Warshall(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<vector<int>> clousre(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            clousre[i][j] = graph[i][j];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                clousre[i][j] = clousre[i][j] || (clousre[i][k] && clousre[k][j]);

    cout << "Transitive clousre Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << clousre[i][j] << "\t";
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
