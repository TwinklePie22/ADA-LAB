#include <iostream>
#include <vector>

using namespace std;

void Warshall(vector<vector<int>>& graph) {
    int n = graph.size();

    vector<vector<int>> closure(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            closure[i][j] = graph[i][j];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                closure[i][j] = closure[i][j] || (closure[i][k] && closure[k][j]);

    cout << "Transitive Closure Matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << closure[i][j] << "\t";
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
